/*
        2d vector<vector<int>> vec = {{1,2,3,4}, {5,6,7,8}, {9,10, 11}};
        vec2D vecClass(vec);

        //class vector2D

        //inside in public I will have two elemens
        like our 2d vector container
        int row; int col;

        //default constructor that initialize my vector

        //next() -> next element

        //hasNext() -> bool
*/

class Vector2D {
private:
    std::vector<int> nums;
    int position = 0;

public:
    Vector2D(std::vector<std::vector<int>>& v) {
        for (const auto& innerVector : v) {
            for (int num : innerVector) {
                nums.push_back(num);
            }
        }
    }

    int next() {
        if (!hasNext()) {
            throw std::out_of_range("No more elements");
        }
        return nums[position++];
    }

    bool hasNext() {
        return position < nums.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */