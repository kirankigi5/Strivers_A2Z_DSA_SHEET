#include <bits/stdc++.h>
using namespace std;

bool is_config_possible(vector<long long int> &barn, long long int C, long long int curr_idx, long long int prev_idx, long long int min_distance)
{
    if (C == 0)
    {
        return true;
    }
    else if (((barn.size() - 1) - curr_idx) + 1 < C || curr_idx == barn.size())
    {
        // if remaining spots are less than remaining cows return false

        return false;
    }
    else
    {
        if (barn[curr_idx] - barn[prev_idx] >= min_distance)
        {
            // place at curr_idx
            return is_config_possible(barn, C - 1, curr_idx + 1, curr_idx, min_distance);
        }
        else
        {
            // move curr_idx by 1
            return is_config_possible(barn, C, curr_idx + 1, prev_idx, min_distance);
        }
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

        // BS on ans

        // since the lowest min possible distance is 1
        long long int start = 1;
        // since the largest min possible distance is barn[N - 1] - barn[0]
        long long int end = barn[N - 1] - barn[0];

        long long int ans = 1;

        while (start <= end)
        {
            long long int mid = start + (end - start) / 2;

            // mid represents min distance b/w all the cows
            // now lets check whether is there any valid config of cows min distance b/w them is >= mid

            // place the first cow at index 0
            bool check = is_config_possible(barn, C - 1, 1, 0, mid);

            if (check)
            {
                if (ans < mid)
                {
                    ans = mid;
                }

                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}