#include <iostream>
#include <vector>
#include <string>
using namespace std;

//分隔字符串函数
//str是输入的字符串，sign是分隔符，将分隔结果存入result中
void split_str(const string &str, const string &sign, vector<string> &result)
{
    string::size_type pos;
    size_t size = str.size();
    for (size_t i = 0; i < size; ++i)
    {
        pos = str.find(sign, i); //从第i个位置查找sign分隔符第一次出现的位置，没有返回npos
        if (pos == str.npos)
        {
            string s = str.substr(i, size);
            result.push_back(s);
            break;
        }
        if (pos < size)
        {
            string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos;
        }
    }
}

vector<string> checkIP(vector<string> ip_array)
{
    size_t n = ip_array.size();
    vector<string> result_vec;

    if (n == 0)
    {
        result_vec.push_back("empty");
        return result_vec;
    }

    result_vec.push_back(to_string(n));

    vector<string>::iterator it = ip_array.begin();
    for (; it != ip_array.end(); ++it)
    {
        vector<string> result_4, result_6;
        split_str(*it, ".", result_4);
        split_str(*it, ":", result_6);

        if (result_4.size() != 4 && result_6.size() != 8)
        {
            result_vec.push_back("这个既不是Ipv4地址也不是Ipv6地址");
            continue;
        }
        if (result_4.size() == 4)
        {
            vector<string>::iterator it_4 = result_4.begin();
            for (; it_4 != result_4.end(); ++it_4)
            {
                int a = atoi((*it_4).c_str());
                if (a < 0 || a > 255)
                {
                    break;
                }
            }
            if (it_4 == result_4.end())
            {
                result_vec.push_back("IPv4");
            }
            else
            {
                result_vec.push_back("这个既不是Ipv4地址也不是Ipv6地址");
            }
        }
        if (result_6.size() == 8)
        {
            vector<string>::iterator it_6 = result_6.begin();
            for (; it_6 != result_6.end(); ++it_6)
            {
                size_t it6_size = (*it_6).size();
                if (it6_size <= 0 || it6_size > 4)
                {
                    break;
                }
                size_t j = 0;
                while (j < it6_size)
                {
                    char s = (*it_6)[j];
                    if ((s >= '0' && s <= '9') || (s >= 'a' && s <= 'f') || (s >= 'A' && s <= 'F'))
                    {
                        ++j;
                    }
                    else
                    {
                        break;
                    }
                }
                if (j != it6_size)
                {
                    break;
                }
            }
            if (it_6 == result_6.end())
            {
                result_vec.push_back("IPv6");
            }
            else
            {
                result_vec.push_back("这个既不是Ipv4地址也不是Ipv6地址");
            }
        }
    }
    return result_vec;
}

/*
int main()
{
    vector<string> ip_array = {"this is not an address", "192.168.1.1", "0000:0123:ff00:00:ff:1234:1111"};
    vector<string> results;
    results = checkIP(ip_array);
    for (vector<string>::iterator it = results.begin(); it != results.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}
*/