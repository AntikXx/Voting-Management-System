# Voting-Management-System

Introduction
The Voting Management System is a basic C++ program that allows users to manage an election by registering voters and candidates, casting votes, and displaying results. The system also lets the user save and load data, so voting data is not lost when the program exits.

Features
1. Menu System The system starts with a simple menu where users can add voters, add candidates, cast votes, view results, display voters, save and load data.
2. Voter and Candidate Management Users can register voters and candidates by entering their IDs and names. Voter and candidate data are stored in lists and tracked throughout the voting process.
3. Voting Process The system makes sure that each voter can only vote once. Votes are cast by entering the voter ID and candidate ID.
4. Data Saving and Loading Users can save voter and candidate information to files and load them back into the system in future sessions.

Class Structure
The program uses three main classes: Voter, Candidate, and VotingSystem.
• Voter Class Handles voter information such as ID, name, and voting status (whether the voter has voted).
o Functions include creating a voter, checking if they’ve voted, and saving voter data to a file.
• Candidate Class Manages candidates, storing their ID, name, and vote count.
o Functions include registering a candidate, recording votes, and saving candidate data to a file.
• VotingSystem Class The main class that controls adding voters, registering candidates, casting votes and saving/loading data.
o Functions include managing all voters and candidates, handling the voting process, and interacting with files for data saving and loading.

Implementation
The system is controlled by a simple menu. Users can add voters and candidates, cast votes, view results, and save or load data. The system prevents voters from voting more than once, and it checks for valid voter and candidate IDs when casting votes.

Conclusion
The Voting Management System is designed to be simple and easy to use. It allows for smooth election management, with features that ensure the integrity of the voting process, such as preventing double votes and saving data for future use.
