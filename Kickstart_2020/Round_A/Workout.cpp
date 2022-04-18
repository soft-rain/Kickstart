#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findMin(vector<int> &m, int max_diff, int k, int n) {
    int start = 1;
    int end = max_diff;
    int answer = max_diff;
    while (start <= end) {
        int mid = (start + end) / 2;
        int count = 0; //추가할 세션의 개수
        int session = m[0]; //첫번째 세션의 시간
        int i = 1;
        while (i < n) { //쭉 반복하면서
            if (session + mid < m[i]) { //현재 세션에 mid값을 더한 것이 다음 세션보다 작으면
                session += mid; //세션에 mid만큼 더해준다
                count++; //추가한 세션 카운트 증가
            } else { //현재 세션에 mid값을 더한 것이 다음 세션보다 크면
                session = m[i]; //현재 세션을 i번째 세션으로 바꿔줌
                i++;
            }
        }
        if (count > k) { //추가해야할 k보다 카운트가 크면 X -> start를 올림
            start = mid + 1;
        } else {
            answer = mid;
            end = mid - 1;
        }
    }
    return answer;
}

int main() {
    int t, n, k;
    cin >> t;
    for (int j = 0; j < t; j++) {
        cin >> n >> k;
        vector<int> m(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> m[i];
        }
        int max_diff = -1;
        for (int i = 1; i < n; i++) {
            max_diff = max(max_diff, m[i] - m[i - 1]);
        }
        cout << "Case #" << j + 1 << ": " << findMin(m, max_diff, k, n) << '\n';
    }
    return 0;

}