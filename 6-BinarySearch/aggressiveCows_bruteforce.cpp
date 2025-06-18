#include <bits/stdc++.h>
using namespace std;

void place_cows_get_max_min(long long int&ans, long long int min_distance_in_curr_configuration, long long int remaining_cows, long long int curr_idx, long long int previous_placed_idx, long long int remaining_stalls, vector<long long int> &barn)
{
    if (remaining_cows == 0)
    {
        ans = max(ans, min_distance_in_curr_configuration);
        return;
    }
    else if (remaining_cows == remaining_stalls)
    {
        // place remaining cows in remaining stalls 

        if (previous_placed_idx != -1)
        {
            long long int new_min_distance = min(min_distance_in_curr_configuration, barn[curr_idx] - barn[previous_placed_idx]);

            place_cows_get_max_min(ans, new_min_distance, remaining_cows - 1, curr_idx + 1, curr_idx, remaining_stalls - 1, barn);
        }
        else
        {
            place_cows_get_max_min(ans, min_distance_in_curr_configuration, remaining_cows - 1, curr_idx + 1, curr_idx, remaining_stalls - 1, barn);
        }
    }
    else
    {
        // no of remaining_stalls > remaining_cows

        // case-1: choose the current stall and place it

        if (previous_placed_idx != -1)
        {
            long long int new_min_distance = min(min_distance_in_curr_configuration, barn[curr_idx] - barn[previous_placed_idx]);


            place_cows_get_max_min(ans, new_min_distance, remaining_cows - 1, curr_idx + 1, curr_idx, remaining_stalls - 1, barn);
        }
        else
        {
            place_cows_get_max_min(ans, min_distance_in_curr_configuration, remaining_cows - 1, curr_idx + 1, curr_idx, remaining_stalls - 1, barn);
        }

        // case-2: do not place at the current_stall
        place_cows_get_max_min(ans, min_distance_in_curr_configuration, remaining_cows, curr_idx + 1, previous_placed_idx, remaining_stalls - 1, barn);
    }
}

int main()
{
    long long int t;

    cin >> t;

    while (t--)
    {
        long long int N, C;

        cin >> N >> C;

        vector<long long int> barn(N);

        for (int i = 0; i < N; i++)
        {
            cin >> barn[i];
        }

        sort(barn.begin(), barn.end());

        // brute force checkall N choose C possibilities

        long long int ans = INT_MIN;

        place_cows_get_max_min(ans, INT_MAX, C, 0, -1, N, barn);

        cout << ans << endl;
    }

    return 0;
}