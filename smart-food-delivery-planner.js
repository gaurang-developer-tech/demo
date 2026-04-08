/************************************************************
 * Lab 3 Smart Food Delivery Planner
 *
 * OBJECTIVE:
 * Practice asynchronous JavaScript patterns including:
 * - Synchronous validation & exception handling
 * - Callback-based async functions
 * - Promise-based APIs
 * - Promisification
 * - Promise chaining
 * - Function result caching
 *
 * NOTE:
 * All external APIs in this lab are SIMULATED using setTimeout.
 * You must complete all TODO sections.
 ************************************************************/

/* ==========================================================
   1. Restaurant Validation (Synchronous)
   ========================================================== */

/**
 * Validates the restaurant name.
 *
 * RULES:
 * - The restaurant name must be a non-empty string
 * - If the input is invalid, THROW an Error
 *
 * @param {string} name
 */
function validateRestaurant(name) {
  const isString = typeof name === "string";
  const isNonEmpty = isString && name.trim().length > 0;

  if (!isNonEmpty) {
    throw new Error("Invalid restaurant name. Please provide a non-empty string.");
  }
}

/* ==========================================================
   2. Restaurant Details API (Callback-Based)
   ========================================================== */

/**
 * Simulates fetching restaurant details from an external API.
 *
 * RULES:
 * - Use an error-first callback: callback(error, data)
 * - Simulate latency using setTimeout
 * - If name === "GhostKitchen", return an error
 * - Otherwise, return a restaurant object
 *
 * Example restaurant object:
 * {
 *   name: "Pasta Palace",
 *   rating: 4.5,
 *   cuisine: "Italian"
 * }
 *
 * @param {string} name
 * @param {function} callback
 */
function fetchRestaurant(name, callback) {
  setTimeout(() => {
    if (name === "GhostKitchen") {
      callback(new Error("Restaurant not found"), null);
      return;
    }

    const restaurantObject = {
      name,
      rating: 4.5,
      cuisine: "Italian"
    };

    callback(null, restaurantObject);
  }, 700);
}

/* ==========================================================
   3. Menu Recommendation API (Promise-Based)
   ========================================================== */

/**
 * Fetches menu recommendations based on restaurant rating.
 *
 * RULES:
 * - Return a Promise
 * - Reject if restaurant data is invalid
 * - Resolve different menu items based on rating
 *   rating >= 4 -> premium menu
 *   rating < 4  -> regular menu
 *
 * @param {object} restaurant
 * @returns {Promise<Array<string>>}
 */
function fetchMenu(restaurant) {
  return new Promise((resolve, reject) => {
    const isValidRestaurant =
      restaurant &&
      typeof restaurant === "object" &&
      typeof restaurant.name === "string" &&
      typeof restaurant.rating === "number";

    if (!isValidRestaurant) {
      reject(new Error("Invalid restaurant data"));
      return;
    }

    setTimeout(() => {
      if (restaurant.rating >= 4) {
        resolve(["Truffle Pasta", "Gourmet Pizza", "Tiramisu"]);
      } else {
        resolve(["Classic Pasta", "Margherita Pizza", "Gelato"]);
      }
    }, 500);
  });
}

/* ==========================================================
   4. Restaurant Data Caching
   ========================================================== */

/**
 * Cache object to store restaurant data.
 * Key   -> restaurant name
 * Value -> restaurant object
 */
const restaurantCache = {};
const pendingRestaurantCallbacks = {};

/**
 * Fetches restaurant data using cache if available.
 *
 * RULES:
 * - If cached data exists, return it immediately
 * - Log when cached data is used
 * - Otherwise, fetch data and store it in cache
 *
 * @param {string} name
 * @param {function} callback
 */
function fetchRestaurantCached(name, callback) {
  if (Object.prototype.hasOwnProperty.call(restaurantCache, name)) {
    console.log(`Using cached data for ${name}`);
    callback(null, restaurantCache[name]);
    return;
  }

  if (Object.prototype.hasOwnProperty.call(pendingRestaurantCallbacks, name)) {
    console.log(`Using cached data for ${name}`);
    pendingRestaurantCallbacks[name].push(callback);
    return;
  }

  pendingRestaurantCallbacks[name] = [callback];

  fetchRestaurant(name, (error, restaurant) => {
    const callbackQueue = pendingRestaurantCallbacks[name] || [];
    delete pendingRestaurantCallbacks[name];

    if (error) {
      callbackQueue.forEach((cb) => cb(error, null));
      return;
    }

    restaurantCache[name] = restaurant;
    callbackQueue.forEach((cb) => cb(null, restaurant));
  });
}

/* ==========================================================
   5. Promisify the Cached Restaurant API
   ========================================================== */

/**
 * Converts fetchRestaurantCached into a Promise-based function.
 *
 * RULES:
 * - Resolve on success
 * - Reject on error
 *
 * @param {string} name
 * @returns {Promise<object>}
 */
function fetchRestaurantAsync(name) {
  return new Promise((resolve, reject) => {
    fetchRestaurantCached(name, (error, data) => {
      if (error) {
        reject(error);
        return;
      }

      resolve(data);
    });
  });
}

/* ==========================================================
   6. Food Order Planning (Promise Chaining)
   ========================================================== */

/**
 * Main function that plans a food order.
 *
 * RULES:
 * - Validate input BEFORE starting async work
 * - Use Promise chaining (DO NOT nest Promises)
 * - Convert synchronous errors into rejected Promises
 * - Handle errors using .catch()
 *
 * @param {string} restaurantName
 * @returns {Promise<object>}
 */
function planOrder(restaurantName) {
  let selectedRestaurant;

  return Promise.resolve()
    .then(() => {
      validateRestaurant(restaurantName);
      return fetchRestaurantAsync(restaurantName);
    })
    .then((restaurant) => {
      selectedRestaurant = restaurant;
      return fetchMenu(restaurant);
    })
    .then((menu) => ({
      restaurant: selectedRestaurant,
      recommendedMenu: menu
    }))
    .catch((error) => {
      const message = `Order planning failed: ${error.message}`;
      console.error("ERROR:", message);
      return { error: message };
    });
}

/* ==========================================================
   7. Test Calls (DO NOT MODIFY)
   ========================================================== */

// Successful request
planOrder("Pasta Palace")
  .then(result => console.log("SUCCESS:", result))
  .catch(err => console.error("ERROR:", err.message));

// Cached request
planOrder("Pasta Palace");

// Failed request
planOrder("GhostKitchen");
