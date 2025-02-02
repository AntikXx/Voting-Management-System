#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class Voter
{
private:
    int id;
    string name;
    bool hasVoted;

public:
    Voter(int _id, string _name) : id(_id), name(_name), hasVoted(false) {}

    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    bool getHasVoted()
    {
        return hasVoted;
    }

    void vote()
    {
        hasVoted = true;
    }

    void saveFile(ofstream& file)
    {
        file << id << " " << name << " " << hasVoted << endl;
    }
};

class Candidate
{
private:
    int id;
    string name;
    int votes;

public:
    Candidate(int _id, string _name) : id(_id), name(_name), votes(0) {}

    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    int getVoteCount()
    {
        return votes;
    }

    void receiveVote()
    {
        votes++;
    }

    void saveFile(ofstream& file)
    {
        file << id << " " << name << " " << votes << endl;
    }
};

class VotingSystem
{
private:
    vector<Voter> voters;
    vector<Candidate> candidates;

public:
    void addVoter(int id, string name)
    {
        voters.push_back(Voter(id, name));
        cout << "Voter added successfully.\n";
    }

    void addCandidate(int id, string name)
    {
        candidates.push_back(Candidate(id, name));
        cout << "Candidate added successfully.\n";
    }

    void castVote(int voterId, int candidateId)
    {
        for (auto& voter : voters)
        {
            if (voter.getId() == voterId)
            {
                if (voter.getHasVoted())
                {
                    cout << "This voter has already voted.\n";
                    return;
                }
                for (auto& candidate : candidates)
                {
                    if (candidate.getId() == candidateId)
                    {
                        voter.vote();
                        candidate.receiveVote();
                        cout << "Vote cast successfully.\n";
                        return;
                    }
                }
                cout << "Candidate not found.\n";
                return;
            }
        }
        cout << "Voter not found.\n";
    }

    void displayResults()
    {
        cout << "\n--- Election Results ---\n";
        for (auto& candidate : candidates)
        {
            cout << candidate.getName() << ": " << candidate.getVoteCount() << " votes\n";
        }
        cout << "------------------------\n";
    }

    void displayVoters()
    {
        cout << "\n--- Registered Voters ---\n";
        for (auto& voter : voters)
        {
            cout << "ID: " << voter.getId() << ", Name: " << voter.getName()
                 << ", Voted: " << (voter.getHasVoted() ? "Yes" : "No") << endl;
        }
        cout << "--------------------------\n";
    }

    void saveData(string voterFile, string candidateFile)
    {
        ofstream voterOut(voterFile), candidateOut(candidateFile);

        for (auto& voter : voters)
        {
            voter.saveFile(voterOut);
        }

        for (auto& candidate : candidates)
        {
            candidate.saveFile(candidateOut);
        }

        voterOut.close();
        candidateOut.close();
        cout << "Data saved successfully.\n";
    }

    void loadData(string voterFile, string candidateFile)
    {
        ifstream voterIn(voterFile), candidateIn(candidateFile);
        int id;
        string name;
        bool voted;
        int votes;

        voters.clear();
        while (voterIn >> id >> name >> voted)
        {
            Voter voter(id, name);
            voters.push_back(voter);
            if (voted) voters.back().vote();
        }
        voterIn.close();

        candidates.clear();
        while (candidateIn >> id >> name >> votes)
        {
            Candidate candidate(id, name);
            for (int i = 0; i < votes; ++i)
            {
                candidate.receiveVote();
            }
            candidates.push_back(candidate);
        }
        candidateIn.close();
        cout << "Data loaded successfully.\n";
    }
};

int main()
{
    VotingSystem votingSystem;
    string voterFile = "voters.txt", candidateFile = "candidates.txt";

    while (true)
    {
        cout << "\nVoting Management System\n";
        cout << "1. Add Voter\n";
        cout << "2. Add Candidate\n";
        cout << "3. Cast Vote\n";
        cout << "4. Display Results\n";
        cout << "5. Display Voters\n";
        cout << "6. Save Data\n";
        cout << "7. Load Data\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            string name;
            cout << "Enter voter ID: ";
            cin >> id;
            cout << "Enter voter name: ";
            cin >> name;
            votingSystem.addVoter(id, name);
            break;
        }
        case 2:
        {
            int id;
            string name;
            cout << "Enter candidate ID: ";
            cin >> id;
            cout << "Enter candidate name: ";
            cin >> name;
            votingSystem.addCandidate(id, name);
            break;
        }
        case 3:
        {
            int voterId, candidateId;
            cout << "Enter voter ID: ";
            cin >> voterId;
            cout << "Enter candidate ID: ";
            cin >> candidateId;
            votingSystem.castVote(voterId, candidateId);
            break;
        }
        case 4:
            votingSystem.displayResults();
            break;
        case 5:
            votingSystem.displayVoters();
            break;
        case 6:
            votingSystem.saveData(voterFile, candidateFile);
            break;
        case 7:
            votingSystem.loadData(voterFile, candidateFile);
            break;
        case 8:
            cout << "Exiting system...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
