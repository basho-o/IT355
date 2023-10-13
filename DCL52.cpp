//DCL52-CPP. Never qualify a reference type with const or volatile
int main() {
    int num = 10;
    int& ref = num;  // Reference type (not const or volatile qualified)

    // Code that uses ref, but doesn't modify it

    return 0;
}
