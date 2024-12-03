#pragma once

#include <vector>

class Grid {
private:
    std::vector<std::vector<int>> data;

public:
    void CreateGrid(const std::vector<std::vector<int>>& inputData);
    const std::vector<std::vector<int>>& GetData() const;
};

