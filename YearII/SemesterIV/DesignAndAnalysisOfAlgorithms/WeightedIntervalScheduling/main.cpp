#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A structure to store the programs.
struct program
{
    // ID of the program.
    int id;
    
    // Starting time of the program.
    int start_time;
    
    // Ending time of the program.
    int end_time;
    
    // Profit on running the program.
    int profit;
    
    // Operator overloaded for sorting programs on the basis of ending time.
    bool operator < (const program& prg) const
    {
        return end_time < prg.end_time;
    }
};

// Comparator for sorting programs on the basis of program ID. 
bool comparator (program prg1, program prg2)
{
    return prg1.id < prg2.id;
}

int previous_runnable_schedule (vector <program> prg, int cur_index)
{
        
    /**
     * @brief 
     * Returns the index of the max profit schedule of programs 
     * to the left of 'cur_index' that can be run along with the 
     * program indexed at 'cur_index' without any conflicts.
     */

    //Using modified binary search since programs are sorted by their ending times.
    
    int left = 0, right = cur_index - 1;
    
    while (left <= right)
    {
        int probe = (left + right) / 2;
        
        /**
         * @brief 
         * If the ending time of probe < the starting time of cur_index and 
         * the ending time of probe + 1 < the starting time of cur_index,
         * then we need to search in the interval to the right of probe.
         *             
         * If the ending time of probe < the starting time of cur_index and 
         * the ending time of probe + 1 >= the starting time of cur_index,
         * then probe is our required index.
         *             
         * If the ending time of probe >= the starting time of cur_index,
         * then we need to search in the interval to the left of probe.
         */

        if (prg[probe].end_time < prg[cur_index].start_time)
        {
            if (probe == cur_index - 1 || prg[probe + 1].end_time >= prg[cur_index].start_time)
            {
                return probe;
            }
            left = probe + 1;
        }
        else
        {
            right = probe - 1;
        }
    }
    
    return -1;
}

vector <program> max_profit_scheduling (vector <program> prg)
{
    int n = prg.size ();   
    
    // Sort the programs according to their ending times.
    sort (prg.begin(), prg.end());
    
    // Maintain an array to store the max profit in scheduling of programs till current index.
    int max_profit [n];
    // max_profit[i] = maximum profit in scheduling of prg[0..i].
    
    // Base Case -> If there is only one program, we will always take it.   
    max_profit[0] = prg[0].profit;
    
    // Maintain an array to backtrack a schedule of programs that gives max profit. 
    int previous [n];
    
    // There is no program prior to the first program.
    previous[0] = -1;
    
    // Maintain an array to track if a program is taken or not in a max profit schedule of programs till current index.
    vector<bool> taken (n, false);
    // taken[i] = true if ith program is taken in max profit schedule of prg[0..i], false otherwise.
    
    // First program is taken.
    taken[0] = true;
    
    for (int i = 1; i < n; i++)
    {
        // Profit when the ith program is not included.
        int profit_excluding_current_program = max_profit[i - 1];
        
        // Profit when the ith program is included.
        int profit_including_current_program = prg[i].profit;
        
        /* 
            Getting the index prior to 'i' with the best schedule for programs
            such that the current program can be run without any conflicts.
        */
        int previous_index = previous_runnable_schedule (prg, i);
        
        /*
            Update the profit when the ith program is included if one or more programs 
            considered previously can be run without any conflicts with the current one.
        */
        if (previous_index != -1)
        {
            profit_including_current_program += max_profit[previous_index];
        }
        
        // Update other variables accordingly. 
        if (profit_including_current_program > profit_excluding_current_program)
        {
            max_profit[i] = profit_including_current_program;
            taken[i] = true;
            previous[i] = previous_index;
        }
        else
        {
            max_profit[i] = profit_excluding_current_program;
            previous[i] = i - 1;
        }
    }
    
    // To store a max profit schedule.
    vector <program> schedule;
    
    int cur = n - 1;
    
    while (cur != -1)
    {
        /**
         * @brief 
         * If the current program is taken in max profit schedule of prg[0..cur],
         * then push it in the schedule.
         */

        if (taken[cur])
        {
            schedule.push_back(prg[cur]);
        }
        
        // Update cur variable to backtrack the previous programs included in the max profit schedule.
        cur = previous[cur];    
    }
    
    return schedule; 
}

// Displays the max profit schedule after sorting it by program ID.
void display (vector <program> schedule)
{
    cout << "Maximum Profit Schedule: -\n\n";
    
    int total_profit = 0;
    
    sort (schedule.begin(), schedule.end(), comparator);
    
    for (program p : schedule)
    {
        cout << "Job ID = " << p.id 
             << ", Start Time = " << p.start_time
             << ", End Time = " << p.end_time
             << ", Profit = " << p.profit
             << "\n\n";
             
        total_profit += p.profit;
    }
    
    cout << "Total Profit = " << total_profit << endl;
}

int main ()
{
    vector <program> prg;
    
    prg.push_back ({1, 1, 3, 20});
    prg.push_back ({2, 3, 6, 20});
    prg.push_back ({3, 5, 12, 100});
    prg.push_back ({4, 7, 9, 70});
    prg.push_back ({5, 10, 14, 60});
    
    // Getting the max profit schedule.
    vector <program> schedule = max_profit_scheduling (prg);
    
    // Displaying the max profit schedule.
    display (schedule);
       
    return 0;
}