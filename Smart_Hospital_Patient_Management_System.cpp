#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Patient {
    int id;
    string name;
    int severity;        // Higher value = more severe
    string department;
    int arrivalTime;

    Patient* left;
    Patient* right;

    Patient(int i, string n, int s, string d, int a)
        : id(i), name(n), severity(s), department(d),
          arrivalTime(a), left(NULL), right(NULL) {}
};

struct ArchiveNode {
    Patient data;
    ArchiveNode* next;

    ArchiveNode(Patient p) : data(p), next(NULL) {}
};

ArchiveNode* archiveHead = NULL;

void archivePatient(Patient p) {
    ArchiveNode* node = new ArchiveNode(p);
    node->next = archiveHead;
    archiveHead = node;
}

class PatientBST {
public:
    Patient* root = NULL;

    Patient* insert(Patient* node, Patient* newPatient) {
        if (!node) return newPatient;
        if (newPatient->id < node->id)
            node->left = insert(node->left, newPatient);
        else
            node->right = insert(node->right, newPatient);
        return node;
    }

    void insertPatient(Patient* p) {
        root = insert(root, p);
    }

    Patient* search(Patient* node, int id) {
        if (!node || node->id == id) return node;
        if (id < node->id) return search(node->left, id);
        return search(node->right, id);
    }

    Patient* searchById(int id) {
        return search(root, id);
    }

    void inorder(Patient* node) {
        if (!node) return;
        inorder(node->left);
        cout << "ID: " << node->id << " Name: " << node->name << endl;
        inorder(node->right);
    }
};

struct Operation {
    string type;
    Patient patient;
};

stack<Operation> undoStack;
stack<Operation> redoStack;

queue<Patient> normalQueue;
deque<Patient> emergencyQueue;
int timeCounter = 0;

void admitPatient(bool emergency) {
    int id, severity;
    string name, department;

    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Severity (1-10): ";
    cin >> severity;
    cout << "Enter Department: ";
    cin >> department;

    Patient p(id, name, severity, department, ++timeCounter);

    if (emergency) {
        emergencyQueue.push_front(p);
        cout << "Emergency patient admitted!\n";
    } else {
        normalQueue.push(p);
        cout << "Patient admitted normally.\n";
    }

    undoStack.push({"ADMIT", p});
    while (!redoStack.empty()) redoStack.pop();
}

void undo() {
    if (undoStack.empty()) {
        cout << "Nothing to undo.\n";
        return;
    }
    Operation op = undoStack.top();
    undoStack.pop();
    redoStack.push(op);
    cout << "Undo operation performed: " << op.type << endl;
}

void redo() {
    if (redoStack.empty()) {
        cout << "Nothing to redo.\n";
        return;
    }
    Operation op = redoStack.top();
    redoStack.pop();
    undoStack.push(op);
    cout << "Redo operation performed: " << op.type << endl;
}

void dischargePatient(PatientBST& bst) {
    if (emergencyQueue.empty() && normalQueue.empty()) {
        cout << "No patients to discharge.\n";
        return;
    }

    Patient p = !emergencyQueue.empty()
                    ? emergencyQueue.front()
                    : normalQueue.front();

    if (!emergencyQueue.empty())
        emergencyQueue.pop_front();
    else
        normalQueue.pop();

    bst.insertPatient(new Patient(p));
    archivePatient(p);

    cout << "Patient discharged & archived.\n";
}

void sortPatients(vector<Patient>& list, int choice) {
    if (choice == 1)
        sort(list.begin(), list.end(),
             [](Patient a, Patient b) { return a.severity > b.severity; });

    else if (choice == 2)
        sort(list.begin(), list.end(),
             [](Patient a, Patient b) { return a.arrivalTime < b.arrivalTime; });

    else if (choice == 3)
        sort(list.begin(), list.end(),
             [](Patient a, Patient b) { return a.department < b.department; });
}

int main() {
    PatientBST bst;
    int choice;

    do {
        cout << "\n===== SMART HOSPITAL SYSTEM =====\n";
        cout << "1. Admit Normal Patient\n";
        cout << "2. Admit Emergency Patient\n";
        cout << "3. Discharge Patient\n";
        cout << "4. Search Patient by ID\n";
        cout << "5. Undo\n";
        cout << "6. Redo\n";
        cout << "7. Display BST\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            admitPatient(false);
            break;
        case 2:
            admitPatient(true);
            break;
        case 3:
            dischargePatient(bst);
            break;
        case 4: {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            Patient* p = bst.searchById(id);
            if (p)
                cout << "Found: " << p->name << " Severity: " << p->severity << endl;
            else
                cout << "Patient not found.\n";
            break;
        }
        case 5:
            undo();
            break;
        case 6:
            redo();
            break;
        case 7:
            bst.inorder(bst.root);
            break;
        }
    } while (choice != 0);

    return 0;
}

