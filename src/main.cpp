#include <iostream>

#include <vector>
#include <map>
#include <deque>

#include <zpp_bits.h>


struct Data {
    std::string msg;
    std::map<std::string, std::string> table;
    std::deque<std::string> buf;
};

int main(int argc, char* argv[]) {
    std::cout << "Cpp Data Serialization\n";

    auto src = Data{
        .msg="Test String, Test String, Test String, ASDFQWERASDFQWERASDFQWERASDFQWER",
        .table={
            {"key1", "val1"},
            {"key2", "val2"},
            {"key3", "val3"},
            {"key4", "val4"},
            {"key5", "val5"},
            {"key________________________________long_______6", "val________________________________long_______6"},
            {"key________________________________long_______7", "val________________________________long_______7"},
            {"key________________________________long_______8", "val________________________________long_______8"},
        },
        .buf={
            "message1",
            "message2",
            "message3",
            "message4",
            "message5",
        }
    };

    auto [data, in, out] = zpp::bits::data_in_out();

    auto result = out(src);
    if (failure(result)) {
        std::cerr << "Serialization Failed" << std::endl;
        std::cerr << "Error Code: " << int(result.code) << std::endl;
        exit(1);
    }

    std::cout << "Bytes: " << data.size() << std::endl;

    Data dst;

    result = in(dst);

    if (failure(result)) {
        std::cerr << "Deserialization Failed" << std::endl;
        std::cerr << "Error Code: " << int(result.code) << std::endl;
        exit(1);
    }

    std::cout << "msg: " << dst.msg << '\n';
    for (const auto&[k, v]: dst.table) {
        std::cout << k << ':' << v << '\n';
    };
    for(const auto& s: dst.buf) {
        std::cout << s << '\n';
    }
    



    return 0;
}