#include <bits/stdc++.h>
using namespace std;

std::vector<char> read_source(std::string&& file_path)
{
    std::ifstream file(file_path);

    std::vector<char> source;

    char c;
    while (file.get(c)) {
        source.push_back(c);
    }

    return source;
}

void filter_chars(std::vector<char>& source)
{
    auto new_end = std::remove_if(source.begin(), source.end(),
                                  [](char c) { return !std::strchr("<>+-[],.", c); });

    source.erase(new_end, source.end());
}

void interpret(string& source)
{
    std::vector<unsigned char> tape(30000, 0);
    int h = 0;

    int brace_count = 0;

    int i = 0;
    while (i < source.size()) {
        switch (source[i]) {
            case '<':
                --h;
                break;
            case '>':
                ++h;
                break;
            case '+':
                ++tape[h];
                break;
            case '-':
                --tape[h];
                break;
            case '.':
                std::cout << tape[h] << std::flush;
                break;
            case ',':
                std::cin >> tape[h];
                break;

            case '[':
                if (tape[h] == 0) {
                    ++brace_count;
                    while (source[i] != ']' || brace_count != 0) {
                        ++i;
                        if (source[i] == '[') {
                            ++brace_count;
                        }
                        else if (source[i] == ']') {
                            --brace_count;
                        }
                    }
                }
                break;

            case ']':
                if (tape[h] != 0) {
                    ++brace_count;
                    while (source[i] != '[' || brace_count != 0) {
                        --i;
                        if (source[i] == ']') {
                            ++brace_count;
                        }
                        else if (source[i] == '[') {
                            --brace_count;
                        }
                    }
                }
                break;

        }
        ++i;
    }
}


int main(int argc, char* argv[]){
    int t;
    cin>>t;
    while(t--) {
        string source = ">,>,>,<[->->+<<]>>[-<<+>>]<<<[->-<<+>]<[->+<]>>>>>>+>>>>>>>+[>>>>[-]<[-]<[-]<[-]<[-]<<<<<<<<<<<<[->>>>>>>+>>>>>>+<<<<<<<<<<<<<]>[->>>>>>>+>>>>>>+<<<<<<<<<<<<<]>[->>>>>>>+>>>>>>+<<<<<<<<<<<<<]>>+>+[<-]<[->>+<<<]>>>>[-<<<<<<<+>>>>>>>]>[-<<<<<<<+>>>>>>>]>[-<<<<<<<+>>>>>>>]>>>>>>>+[-<<<<<<<<<<<[->>+>>+<<<<]>[->>+>>+<<<<]>[-<<+>>]>[-<<+>>]+[[-]+>[<-]<[->>-<<<]>>->>>+>[<-]<[->+>[-<-]<[>>[-<<->]-<<[->->>-<<<<]]<]>>-<<<<<+>[<-]<[>>[<<->]<<[<]]>-]>>>>>>>>+]-<<<<+>+[<-]<[>>+[<<->]<<[>>>+[<<<->>]<<<[<]]]>-]>>>>[-]<<<<<<<<<<<<<<[-]>>+>+[<-]<[->>+<<<]>+>[<-]<[>>[<<->]<<[<]]>-[+>>>>>>++++++++++<<<<<<+>[<-]<[>>[<<->]<<[<]]>-[++>[<-]<[->>-<<<]>>->>+>>+>-[<-]<[<<[->>>+<<<]>>>>>+>+[<-]<[->>+<<<]<<-<]<<<<+>[<-]<[>>[<<->]<<[<]]>-]>>++++++++[->++++++<]>[-<<<<+>>>>]>>>>>+>[<-]<[>>[<<->]<<[<]]>-[++>[<-]<[->>-<<<]>>-<<<<<<<<+>+[<-]<[->>+<<<]>>>>>>>>+>[<-]<[>>[<<->]<<[<]]>-]<<[-]<<<<<+>[<-]<[>>[<<->]<<[<]]>-]<<[.<]";
        interpret(source);
        cout<<"\n";
    }
}