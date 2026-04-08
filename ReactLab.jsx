import React from "react";

function ProfileCard(props) {
  return (
    <div style={{ 
      border: "1px solid #ddd", 
      borderRadius: "8px", 
      padding: "20px", 
      margin: "10px",
      display: "flex", 
      flexDirection: "column", 
      alignItems: "center",
      boxShadow: "0 4px 8px rgba(0,0,0,0.1)",
      backgroundColor: "white",
      transition: "transform 0.2s"
    }}>
     
      {/* Q1.1: Display image using props.image */}
      <img src={props.image} alt="profile" width="100" style={{ borderRadius: "50%", marginBottom: "15px" }} />

      {/* Q1.2: Display name using props.name */}
      <h3 style={{ margin: "5px 0", color: "#333" }}>{props.name}</h3>

      {/* Q5: Add a button inside ProfileCard that shows alert with student name */}
      <button 
        onClick={() => alert(`Student Name: ${props.name}`)}
        style={{
          marginTop: "15px",
          padding: "8px 16px",
          backgroundColor: "#007BFF",
          color: "white",
          border: "none",
          borderRadius: "4px",
          cursor: "pointer",
          fontWeight: "bold"
        }}
      >
        Show Name
      </button>

    </div>
  );
}

const students = [
  { name: "John Doe", image: "https://via.placeholder.com/100?text=John" },
  { name: "Jane Smith", image: "https://via.placeholder.com/100?text=Jane" },
  { name: "Alice Johnson", image: "https://via.placeholder.com/100?text=Alice" },
  { name: "Bob Brown", image: "https://via.placeholder.com/100?text=Bob" },
  { name: "Charlie Davis", image: "https://via.placeholder.com/100?text=Charlie" },
  { name: "Diana Evans", image: "https://via.placeholder.com/100?text=Diana" },
  { name: "Evan Foster", image: "https://via.placeholder.com/100?text=Evan" },
  { name: "Fiona Green", image: "https://via.placeholder.com/100?text=Fiona" }
];

// Q3: Display list using map()
function StudentList() {
  return (
    <div style={{ padding: "20px" }}>
      <h2 style={{ textAlign: "center", marginBottom: "20px", color: "#444" }}>Student List</h2>

      {/* Q6: Add more styling (flexbox / grid) */}
      <div style={{
        display: "grid",
        gridTemplateColumns: "repeat(auto-fit, minmax(220px, 1fr))",
        gap: "20px",
        padding: "10px"
      }}>
        {students.map((student, index) => (
          <ProfileCard key={index} name={student.name} image={student.image} />
        ))}
      </div>

    </div>
  );
}

// Q4: Main App component
function App() {
  return (
    <div style={{ fontFamily: "Arial, sans-serif", backgroundColor: "#f9f9f9", minHeight: "100vh" }}>
      <h1 style={{ textAlign: "center", padding: "20px", margin: 0, backgroundColor: "#282c34", color: "white" }}>
        React Lab - Student Profiles
      </h1>

      {/* Render StudentList here */}
      <StudentList />

    </div>
  );
}

export default App;
