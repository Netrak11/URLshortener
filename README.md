#Acknowledgments:
I am currently a 19-year-old computer science student at Elgin community college. Before this project, my experience was limited strictly to console applications within C++,Python and Java. In order to complete this "Full-Stack" requirement, I utilized AI to learn:
*How to bridge C++ logic with a web browser using the Crow framework.
*Basic REST API design (POST, GET, and Redirects).
*JavaScript for the frontend UI.

besides AI I received additional help from my brother(a fellow software engineer) to help clarify and provide a deeper understanding about APIs and frontend development(IE: Javascript).


#Description:
This is a full-stack URL Shortener The application allows users to submit long URLs and receive a unique, 6-character short code that redirects them to the original destination


#Setup/Run instructions:
*Backend: C++17 (Visual Studio 2022).
*Web Framework: Crow C++.
*Frontend: JavaScript.

1. Prerequisites
*Visual Studio 2022 with the "Desktop development with C++" workload installed.
*vcpkg (C++ Package Manager) to install the Crow library.

2. Setup
*Clone the repository and open the .sln file in Visual Studio.
*Ensure the project properties are set to C++17 Standard or higher.
*Verify that the templates folder containing index.html is in your project directory.

3. Launch
*Ensure VS code is set to x64 before running.
*Press F5 in Visual Studio to start the backend server.
*Open your browser and navigate to: http://localhost:18080

#Trade-offs & Assumptions:
*I chose an unordered_map for storage. While this means data is lost if the server restarts


#Desired Expansions:
If I had a better understanding on APIs and more time I would've loved to work on adding all of the bonus features 
*Click Tracking
*Custom short code
*URL expiration

#Testing:
To ensure the backend logic was functional before building the UI, I used the Postman Desktop App to test the API routes manually:
POST /shorten: Sent JSON payloads containing long URLs to verify code generation and map storage.
GET /list: Verified the backend correctly returned the full collection of shortened links as a JSON object.
GET /<shortCode>: Tested the redirect logic to ensure 404 errors for invalid codes and 301/302 redirects for valid ones

