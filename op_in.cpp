#include <vector>
#include <string>


// verification of the occurrence
bool op_in(const std::string &verifiable, std::vector<std::string> &root)
{
    for (const auto& i: root)
    {
        if (verifiable == i) return true;
    }
    return false;
}