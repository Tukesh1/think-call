#include <map>
#include <iostream>
#include <iomanip>
#include <iostream>
template <typename K, typename V>
class interval_map
{
    friend void IntervalMapTest();
    V m_valBegin;
    std::map<K, V> m_map;

public:
    // constructor associates whole range of K with val
    interval_map(V const &val) : m_valBegin(val) {}

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign(K const &keyBegin, K const &keyEnd, V const &val)
    {
       // write your code here 
    }
    // look-up of the value associated with key
    V const &operator[](K const &key) const
    {
        auto it = m_map.upper_bound(key);
        if (it == m_map.begin())
        {
            return m_valBegin;
        }
        else
        {
            return (--it)->second;
        }
    }
};

// Test function
int main()
{
    // instance of interval_map class
    interval_map<int, char> m('A');
    // calling of assign() function
    m.assign(1, 3, 'B');
    // loop for maping key and its corresponding value
    for (int i = -3; i <= 5; ++i)
        std::cout << std::setw(2) << i << ' ' << m[i] << '\n';
}
