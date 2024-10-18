#include <iostream>
#include <string>

using namespace std;

class Assignment {
    private:
    int points;
    int totalPoints;

    public:

    Assignment(int points, int totalPoints) {
        this->setPoints(points);
        this->setTotalPoints(totalPoints);
    }

    int getPoints() {
        return points;
    }

    void setPoints(int points) {
        this->points = points;
    }

    int getTotalPoints() {
        return totalPoints;
    }

    void setTotalPoints(int totalPoints) {
        this->totalPoints = totalPoints;
    }

    Assignment operator+(Assignment& s) {
        return Assignment(
            this->getPoints() + s.getPoints(),
            this->getTotalPoints() + s.getTotalPoints()
        );
    }
}

class Student {
    private:
    string name;
    Assignment* assignments;
    int assignmentCount;

    public:

    Student(string name, Assignment* assignments, int assignmentCount) {
        this->setName(name);
        this->assignments = assignments;
        this->assignmentCount = assignmentCount;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    Assignment* getAssignments() {
        return assignments;
    }

    void setAssignments(Assignment* assignments, int assignmentCount) {
        this.assignments = assignments;
        this.assignmentCount = assignmentCount;
    }

    int getAssignmentCount() {
        return assignmentCount;
    }

    Assignment sumAssignments() {
        Assignment sum = Assignment(0, 0);
        
        for (int i = 0; i < assignmentCount; i++) {
            sum = sum + assignments[i];
        }

        return sum;
    }
}

int main() {
    Assignment assignments[] = {
        Assignment(5, 10),
        Assignment(10, 15),
        Assignment(18, 20),
        Assignment(86, 100)
    };

    Student student = Student("Michael", assignments, 4);

    Assignment sum = student.sumAssignments();

    cout << student.getName() << ": Points: " << sum.getPoints() << "  Total Points: " << sum.getTotalPoints() << endl;

    return 0;
}