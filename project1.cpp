# include <iostream>
# include "process.hpp"
using namespace std;


void insertionSort(process proc[], int arraylength, string sortBy){ //NOTE TO GAB: I KNOW ITS INSERTION SORT BUT I'M LAZY HAHAHAHHA
    int j;
    int k;
    int i;
    process temp;
    cout << "Array Length: " << arraylength << endl;
    if(sortBy == "Arrival"){    
        for (i = 1; i < arraylength; i++){
            k = proc[i].arrival;
            j = i - 1;
            while (j >= 0 && k <= proc[j].arrival){
                temp = proc[j + 1];
                proc[j + 1] = proc[j];
                proc[j] = temp;
                j = j - 1;
            }
        }
    }

    if(sortBy == "Burst"){    
        for (i = 1; i < arraylength; i++){
            k = proc[i].burst;
            j = i - 1;
            while (j >= 0 && k <= proc[j].burst){
                temp = proc[j + 1];
                proc[j + 1] = proc[j];
                proc[j] = temp;
                j = j - 1;
            }
        }
    }

    if(sortBy == "Priority"){    
        for (i = 1; i < arraylength; i++){
            k = proc[i].priority;
            j = i - 1;
            while (j >= 0 && k <= proc[j].priority){
                temp = proc[j + 1];
                proc[j + 1] = proc[j];
                proc[j] = temp;
                j = j - 1;
            }
        }
    }
    /*
    copy and put inside of if statements to check if they're sorted
    cout << "Sorted Array: " << endl;
    for (int p = 0; p < arraylength; p++){
        cout << proc[p].arrival << " ";
        cout << proc[p].burst << " ";
        cout << proc[p].priority << endl;
    }
    */
}

int FCFS(int processCount, process bruh[]){ //first come first served
    insertionSort(bruh, processCount, "Arrival");
    for (int i = 0; i < processCount; i++){
        cout << bruh[i].arrival << " " << bruh[i].index << " " << bruh[i].burst << "X" << endl;
    }
    return 0;
}

int SJF(int processCount, process bruh[]){ // Shortest Job First (non-preemptive)
    // shortest burst first
    insertionSort(bruh, processCount, "Burst");
    for (int i = 0; i < processCount; i++){
        cout << bruh[i].arrival << " " << bruh[i].index << " " << bruh[i].burst << "X" << endl;
    }
    return 0;
}

int SRTF(){ // Shortest Remaining Time First
    return 0;
}

int Priority(int processCount, process bruh[]){ // Priority (preemptive)
    insertionSort(bruh, processCount, "Priority");
    for (int i = 0; i < processCount; i++){
        cout << bruh[i].arrival << " " << bruh[i].index << " " << bruh[i].burst << "X" << endl;
    }
    return 0;
}

int RR(){ // Round-Robin
    return 0;
}

int main(){ //main just handles getting inputs and passing stuff into functions based on inputs
    int testCases;
    int processesCount;
    string processType;
    cout << "Number of Test Cases: ";
    cin >> testCases;
    
    for(int k = 0; k < testCases; k++){
        cout << "Process Details: ";
        cin >> processesCount; // declare with each new test case
        cin >> processType;
        process processArray[processesCount];
        for (int bruh = 0; bruh < processesCount; bruh++){
            process p;

            cin >> p.arrival;
            cin >> p.burst;
            cin >> p.priority;
            p.index = bruh + 1;

            processArray[bruh] = p;
        }
        /*
        check if counted properly
        int arraylength = sizeof(processArray)/sizeof(processArray[0]);
        cout << "PEEPEE POOPOO: " << arraylength << endl;
        */
        

        /* check if stored properly
        cout << "Process Array: " << endl;
        for (int p = 0; p < processesCount; p++){
            cout << processArray[p].arrival << endl;
            cout << processArray[p].burst << endl;
            cout << processArray[p].priority << endl;
        }
        */
        if (processType == "FCFS"){
            cout << k << " FCFS" << endl;
            FCFS(processesCount, processArray);
        }
        if (processType == "SJF"){
            cout << k << " SJF" << endl;
            SJF(processesCount, processArray);
        }
        if (processType == "P"){
            cout << k << " P" << endl;
            Priority(processesCount, processArray);
        }
    }
}