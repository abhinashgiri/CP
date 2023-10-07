 # 256MB stack limit
g++ -std=c++17 sol.cpp -o sol -Wl,-stack_size,0x10000000,-stack_addr,0xc0000000

# 1GB stack limit
# g++ -std=c++17 sol.cpp -o sol -Wl,-stack_size,0x40000000,-stack_addr,0xc0000000 -Wextra -Wall -fsanitize=address -fsanitize=undefined

./sol < t.txt 

