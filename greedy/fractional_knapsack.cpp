#include <bits/stdc++.h>
using namespace std;

struct node
{
    long long time, speed, cost;

    node() : time(0), speed(0), cost(0){};
};

bool check(node a, node b)
{
    if (a.time != b.time)
        return a.time < b.time;
    else if (a.speed != b.speed)
        return a.speed > b.speed;

    return a.cost < b.cost;
}

int main()
{
    long long n, d;
    cin >> n >> d;
    node *arr = new node[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i].time >> arr[i].cost >> arr[i].speed;
    }

    sort(arr, arr + n, check);
    long long area = 0;
    long long cost = 0;
    long long speed = 0;
    long long prev = arr[0].time;
    for (long long i = 0; i < n; i++)
    {
        long long temp = speed * (arr[i].time - prev);
        area += temp;
        if (area >= d)
            break;
        if (arr[i].speed > speed)
        {
            speed = arr[i].speed;
            cost += arr[i].cost;
        }
        prev = arr[i].time;
    }
    cout << cost << "\n";
}