#include <iostream>
#include <string>
#include <memory> 
using namespace std;

class Question {
    private:
        string question;
        string answerA;
        string answerB;
        string answerC;
        string answerD;
        char rightAnswer;

    public:
        Question(string question, string answerA, string answerB, string answerC, string answerD, char rightAnswer) {
            this->question = question;
            this->answerA = answerA;
            this->answerB = answerB;
            this->answerC = answerC;
            this->answerD = answerD;
            this->rightAnswer = rightAnswer;
        }

        friend ostream& operator<<(ostream& out, const Question& q);

        bool checkRightAnswer(char& ch) const {
            return this->rightAnswer == ch;
        }
};

ostream& operator<<(ostream& out, const Question& q) {
    out << q.question << endl;
    out << "a) " << q.answerA << endl;
    out << "b) " << q.answerB << endl;
    out << "c) " << q.answerC << endl;
    out << "d) " << q.answerD << endl;

    return out;
}

class Quiz {
    private:
        unique_ptr<vector<Question>> questions;
        int questionCount;
        int size;
    
    public:
        Quiz(int questionCount) {
            this->questions = make_unique<vector<Question>>();
            this->questionCount = questionCount;
            this->size = 0;
        }

        void operator+=(Question q) {
            if(this->questionCount == this->questions->size()) {
                throw out_of_range("Limit questions is: " + to_string(this->questionCount));
            }

            this->questions->push_back(q);
            this->size += 1;
        }

        void start() const {
            int rightCount = 0;
            char value;

            for (const Question& q : *questions) {
                cout << q << endl;

                cin >> value;

                bool isRightAnswer = q.checkRightAnswer(value);

                if(isRightAnswer) {
                    rightCount += 1;
                }
            }

            cout << "Total score: " << rightCount << endl;
        }
};

int main() {
    Quiz quiz(3);

    Question q("question", "answerA", "answerB", "answerC", "answerD", 'd');

    quiz += q;

    Question q1("question1", "answerA", "answerB", "answerC", "answerD", 'a');

    quiz += q1;

    Question q2("question2", "answerA", "answerB", "answerC", "answerD", 'c');

    quiz += q2;

    quiz.start();

    return 0;
}