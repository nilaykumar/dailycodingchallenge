int main() {
    const unsigned int N = 17;
    const unsigned int numbers[] = {10, 15, 3, 7};
    bool present[N];
    for(unsigned int i = 0; i < N; i++)
        present[i] = false;
    for(auto i : numbers) {
        if(i > N)
            continue;
        if(present[N - i]) {
            return 0;
        }
        present[i] = true;
    }
    return 1;
}
