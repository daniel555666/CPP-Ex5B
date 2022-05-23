#include <iostream>
#include <string>
#include "Node.hpp"
using namespace std;

namespace ariel
{

    class OrgChart
    {

    public:
        Node *head;
        OrgChart &add_root(string root);
        OrgChart &add_sub(string bos, string object);
        vector<Node*> *lvls;
        size_t highest_lvl;

        OrgChart()
        {            
            this->head = NULL;
        }

        iterator end();
        iterator begin();
        iterator begin_level_order();
        iterator end_level_order();
        iterator begin_reverse_order();
        iterator reverse_order();
        iterator begin_preorder();
        iterator end_preorder();
        ~OrgChart();

    private:
        iterator DFS( vector<Node*> v,Node* head);
        Node *DFS_get_bos(string bos, Node *root);
        friend ostream &operator<<(ostream &output, OrgChart &org);
    };

}