using namespace std;

long long solution(int price, int money, int count)
{
    long long balance = (long long)money;
    
    for (int i = 1 ; i <= count ; i++) {
        balance -= (price * i);
    }
    return balance >= 0 ? 0 : -balance;
}
