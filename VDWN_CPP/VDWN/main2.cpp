#include <iostream>
#include <vector>

using std::vector, std::cout, std::endl;

bool is_arithmetic_progression_of_colour(const std::vector<int> &sublist, int length, int colour)
{
    for (int i = 0; i < sublist.size(); ++i)
    {
        if (sublist[i] != colour)
            continue;
        for (int j = i + 1; j < sublist.size(); ++j)
        {
            if (sublist[j] != colour)
                continue;
            int common_diff = j - i;
            bool valid = true;
            for (int k = 0; k < length; ++k)
            {
                int index = i + common_diff * k;
                if (index >= sublist.size() || sublist[index] != colour)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
                return true;
        }
    }
    return false;
}

vector<int> current_c(vector<int> c, int index)
{
    vector<int> v;
    for (int i = 1; i <= index; i++)
    {
        v.push_back(c[i]);
    }
    return v;
}

bool all_equal(vector<int> t, int j)
{
    for (int i = j; i < t.size(); i++)
        if (t[i] != t[j])
            return false;
    return true;
}

bool greater_than_all(vector<int> c, int ind)
{
    for (int l = 0; l <= ind; l++)
    {
        if (c[ind + 1] <= c[l])
        {
            return false;
        }
    }
    return true;
}

int j_val(vector<int> t)
{
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] != 2)
        {
            return i;
        }
    }
    throw;
}

int zeroCount = 0;
int max = 0;
vector<int> c(1000, 0);
vector<int> t = {2, 2, 2, 2, 2, 2, 2, 2, 3, 3};
void run(int k, int j, int ind, int x)
{
    if (zeroCount > j)
        return;
    if (ind > 0 && x > 0)
        if (is_arithmetic_progression_of_colour(current_c(c, ind), t[x + j - 1], x))
            return;

    if (ind > max)
    {
        max = ind;
        std::cout << max << std::endl;
    }
    for (int i = 0; i <= k - j; i++)
    {
        if (i == 0)
            zeroCount++;
        c[ind + 1] = i;
        run(k, j, ind + 1, i);
        if (i == 0)
            zeroCount--;
        if (i > 0 && all_equal(t, j))
            if (ind <= j + (i - 1) * (t[j] - 1) + 1)
                if (greater_than_all(c, ind))
                    break;
    }
}

int main()
{

    cout << "W(" << t.size() << ";";
    for (int i = 0; i < t.size() - 1; i++)
    {
        cout << t[i] << ",";
    }
    cout << t[t.size() - 1] << ") = ?" << endl;

    run(t.size(), j_val(t), 0, 0);

    cout << "W(" << t.size() << ";";
    for (int i = 0; i < t.size() - 1; i++)
    {
        cout << t[i] << ",";
    }
    cout << t[t.size() - 1] << ") = " << max + 1 << endl;
}