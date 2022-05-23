#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> table[board.size()];
    stack<int> basket;
    
    for (int i = 0 ; i < board.size() ; i++) {
        for (int j = board.size() - 1 ; j >= 0 ; j--) {
            table[i].push(board[j][i]); // 2차원 배열의 내용을 뒤에서부터 인덱스별로 스택에 넣기
        }
    }
    for (int i = 0 ; i < moves.size() ; i++) {
        int pick = moves[i] - 1; // 세로 줄 선택
        while (table[pick].size() && !table[pick].top()) {
            table[pick].pop(); // 세로 줄에서 0 (공백) 제거
        }
        if (table[pick].size()) {
            int doll = table[pick].top(); // 인형 선택
            table[pick].pop();
            if (basket.size() && basket.top() == doll) { // 바구니의 맨위랑 같으면 삭제
                basket.pop();
                answer += 2;
            } else {
                basket.push(doll);
            }
        }   
    }
    return answer;
}
