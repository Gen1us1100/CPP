/*A Dictionary stores keywords and its meanings. Provide facility for adding new 
keywords, deleting keywords, updating values of any entry. Provide facility to display 
whole data sorted in ascending/ Descending order. Also find how many maximum 
comparisons may require for finding any keyword. Use Binary Search Tree for 
implementation

code generated by ChatGPT
*/

#include <iostream>
#include <string>

class TreeNode {
public:
    std::string keyword;
    std::string meaning;
    TreeNode* left;
    TreeNode* right;

    TreeNode(std::string keyword, std::string meaning)
        : keyword(keyword), meaning(meaning), left(nullptr), right(nullptr) {}
};

class Dictionary {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, std::string keyword, std::string meaning) {
        if (node == nullptr)
            return new TreeNode(keyword, meaning);

        if (keyword < node->keyword)
            node->left = insertNode(node->left, keyword, meaning);
        else if (keyword > node->keyword)
            node->right = insertNode(node->right, keyword, meaning);

        return node;
    }

    TreeNode* deleteNode(TreeNode* node, std::string keyword) {
        if (node == nullptr)
            return node;

        if (keyword < node->keyword)
            node->left = deleteNode(node->left, keyword);
        else if (keyword > node->keyword)
            node->right = deleteNode(node->right, keyword);
        else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* successor = findMinNode(node->right);
            node->keyword = successor->keyword;
            node->meaning = successor->meaning;
            node->right = deleteNode(node->right, successor->keyword);
        }

        return node;
    }

    TreeNode* findMinNode(TreeNode* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    TreeNode* searchNode(TreeNode* node, std::string keyword) {
        if (node == nullptr || node->keyword == keyword)
            return node;

        if (keyword < node->keyword)
            return searchNode(node->left, keyword);

        return searchNode(node->right, keyword);
    }

    void displayInOrderTraversal(TreeNode* node) {
        if (node == nullptr)
            return;

        displayInOrderTraversal(node->left);
        std::cout << node->keyword << ": " << node->meaning << std::endl;
        displayInOrderTraversal(node->right);
    }

    void displayDescendingOrderTraversal(TreeNode* node) {
        if (node == nullptr)
            return;

        displayDescendingOrderTraversal(node->right);
        std::cout << node->keyword << ": " << node->meaning << std::endl;
        displayDescendingOrderTraversal(node->left);
    }

    int getMaxComparisons(TreeNode* node, std::string keyword, int count) {
        if (node == nullptr || node->keyword == keyword)
            return count;

        if (keyword < node->keyword)
            return getMaxComparisons(node->left, keyword, count + 1);

        return getMaxComparisons(node->right, keyword, count + 1);
    }

public:
    Dictionary() : root(nullptr) {}

    void insert(std::string keyword, std::string meaning) {
        root = insertNode(root, keyword, meaning);
    }

    void remove(std::string keyword) {
        root = deleteNode(root, keyword);
    }

    void update(std::string keyword, std::string newMeaning) {
        TreeNode* node = searchNode(root, keyword);
        if (node != nullptr)
            node->meaning = newMeaning;
    }

    void displayAscendingOrder() {
        displayInOrderTraversal(root);
    }

    void displayDescendingOrder() {
        displayDescendingOrderTraversal(root);
    }

    int getMaxComparisons(std::string keyword) {
        return getMaxComparisons(root, keyword, 1);
    }
};

int main() {
    Dictionary dict;
    dict.insert("Apple", "A fruit");
    dict.insert("Ball", "A spherical object");
    dict.insert("Cat", "A domestic animal");

    std::cout << "Dictionary entries in ascending order:\n";
    dict.displayAscendingOrder();

    std::cout << "\nDictionary entries in descending order:\n";
    dict.displayDescendingOrder();

    std::cout << "\nMaximum comparisons required for searching 'Ball': "
              << dict.getMaxComparisons("Ball") << std::endl;

    dict.update("Apple", "A juicy fruit");
    dict.remove("Cat");

    std::cout << "\nUpdated dictionary entries in ascending order:\n";
    dict.displayAscendingOrder();

    return 0;
}
