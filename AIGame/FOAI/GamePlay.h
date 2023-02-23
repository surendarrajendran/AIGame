#pragma once
#include<iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

namespace FOAI {

    static int gamestarter;

    class _node {
    public:
        string id, numbers;
        int p1, p2, level, hvalue;
        vector<string> descendents;

        _node() { }

        _node(string _id, string _numbers, int _p1, int _p2, int _level) {
            id = _id;
            numbers = _numbers;
            p1 = _p1;
            p2 = _p2;
            level = _level;
        }

        bool charcheck(char c) {
            if (numbers.find(c) != std::string::npos)
                return true;
            else
                return false;
        }
    };

    static vector<_node> nodes_generated = {};
    static int j = 2;
    static string number_used;
    static _node current_node;
    static _node current_game_node;
    static _node received_node;
    static _node current_chosen_node;
    static _node nomore_node("00", "00", -1, -1, -1);


    class GameTree {

    public:
        vector<_node> set_of_nodes;
        vector<pair <string, string> >set_of_arcs;

        GameTree() {
            set_of_nodes = {};
            set_of_arcs = {};
        }

        void add_node(_node n) {
            set_of_nodes.push_back(n);
        }

        void add_arc(string initial_node_id, string end_node_id) {
            set_of_arcs.push_back(make_pair(initial_node_id, end_node_id));
        }

        void assign_descendents() {
            for (auto i = 0; i < set_of_arcs.size(); ++i) {
                for (auto j = 0; j < set_of_nodes.size(); ++j) {
                    if (set_of_arcs[i].first == set_of_nodes[j].id) {
                        set_of_nodes[j].descendents.push_back(set_of_arcs[i].second);
                    }
                }
            }
        }
    };

    static GameTree gt;



    void tree_creation(char type_of_move, _node current_node) {

        static int level;
        level = 2;
        string new_id, changed_string;
        size_t position;
        int new_p1, new_p2, new_level;

        if (current_node.charcheck(type_of_move)) {
            new_id = 'A' + to_string(j);
            j += 1;

            changed_string = current_node.numbers;
            position = changed_string.find(type_of_move);

            changed_string = changed_string.substr(0, position) + changed_string.substr(position + 1);

            if (current_node.level % 2 == 0) {
                new_p1 = current_node.p1;
                new_p2 = current_node.p2 + int(type_of_move - 48);
            }
            else {
                new_p1 = current_node.p1 + int(type_of_move - 48);
                new_p2 = current_node.p2;
            }

            new_level = current_node.level + 1;
            _node new_node(new_id, changed_string, new_p1, new_p2, new_level);

            bool duplicate = false;
            int i = 0;
            while ((!duplicate) && (i <= gt.set_of_nodes.size() - 1)) {
                _node temp = gt.set_of_nodes[i];
                if ((temp.numbers == changed_string) && (temp.p1 == new_p1) && (temp.p2 == new_p2) && (temp.level == new_level)) {
                    duplicate = true;
                }
                else
                    i += 1;
            }
            if (!duplicate) {
                nodes_generated.push_back(new_node);
                gt.add_node(new_node);
                gt.add_arc(current_node.id, new_id);
            }
            else {
                level -= 1;
                gt.add_arc(current_node.id, gt.set_of_nodes[i].id);
            }
        }
    }

    void assign_hvalues() {

        int maxlevel = gt.set_of_nodes[gt.set_of_nodes.size() - 1].level;

        for (int i = int(gt.set_of_nodes.size() - 1); i >= 0; i--) {
            if (gt.set_of_nodes[i].level == maxlevel) {
                int temp_p1 = gt.set_of_nodes[i].p1;
                int temp_p2 = gt.set_of_nodes[i].p2;

                if (temp_p1 > temp_p2)
                    gt.set_of_nodes[i].hvalue = 1;

                else if (temp_p1 < temp_p2)
                    gt.set_of_nodes[i].hvalue = -1;

                else
                    gt.set_of_nodes[i].hvalue = 0;
            }
            else {
                static vector<int> list_of_values;

                for (auto j = 0; j < gt.set_of_arcs.size(); ++j) {
                    if (gt.set_of_arcs[j].first == gt.set_of_nodes[i].id) {
                        for (int k = int(gt.set_of_nodes.size() - 1); k > i; k--) {
                            if (gt.set_of_arcs[j].second == gt.set_of_nodes[k].id)
                                list_of_values.push_back(gt.set_of_nodes[k].hvalue);
                        }
                    }
                }


                if (gt.set_of_nodes[i].level % 2 == 0)
                    gt.set_of_nodes[i].hvalue = *min_element(list_of_values.begin(), list_of_values.end());

                else
                    gt.set_of_nodes[i].hvalue = *max_element(list_of_values.begin(), list_of_values.end());

                list_of_values.clear();
            }
        }
    }

    _node first_comp_move(_node current_node)
    {
        static vector<string> temp_descendents = current_node.descendents;
        static vector<int> temp_descendents_hvalues;
        static _node max_node = current_node;

        for (auto i = 0; i < temp_descendents.size(); i++) {
            for (auto j = 0; j < gt.set_of_nodes.size(); j++) {
                if (temp_descendents[i] == gt.set_of_nodes[j].id) {
                    temp_descendents_hvalues.push_back(gt.set_of_nodes[j].hvalue);
                }
            }
        }

        auto max_element_index = max_element(temp_descendents_hvalues.begin(), temp_descendents_hvalues.end()) - temp_descendents_hvalues.begin();

        for (auto i = 0; i < gt.set_of_nodes.size(); i++) {
            if (gt.set_of_nodes[i].id == temp_descendents[max_element_index]) {
                max_node = gt.set_of_nodes[i];
            }
        }
        return max_node;
    }

    _node gameplay(_node current_node, char current_move, int gamestarter) {
        if(current_node.charcheck(current_move)) {

            static vector<string> temp_descendents;
            static size_t position;
            static vector<int> temp_descendents_hvalues;

            temp_descendents = current_node.descendents;
            position = current_node.numbers.find(current_move);
            temp_descendents_hvalues.clear();

            current_node.numbers = current_node.numbers.substr(0, position) + current_node.numbers.substr(position + 1);
            if (gamestarter == 2)
                current_node.p1 = current_node.p1 + int(current_move - 48);
            else
                current_node.p2 = current_node.p2 + int(current_move - 48);

            for (auto i = 0; i < temp_descendents.size(); i++) {
                for (auto j = 0; j < gt.set_of_nodes.size(); j++) {
                    if (temp_descendents[i] == gt.set_of_nodes[j].id && gt.set_of_nodes[j].p1 == current_node.p1 && gt.set_of_nodes[j].p2 == current_node.p2 && gt.set_of_nodes[j].numbers == current_node.numbers) {
                        current_node = gt.set_of_nodes[j];
                        break;
                    }
                }
            }

            current_chosen_node = current_node;

            if (current_chosen_node.descendents.empty()) {
                return nomore_node;
            }

            temp_descendents = current_node.descendents;

            for (auto i = 0; i < current_node.descendents.size(); i++) {
                for (auto j = 0; j < gt.set_of_nodes.size(); j++) {
                    if (current_node.descendents[i] == gt.set_of_nodes[j].id)
                        temp_descendents_hvalues.push_back(gt.set_of_nodes[j].hvalue);
                }
            }

            static _node maxormin_node = current_node;
            static size_t maxormin_index;
            if (gamestarter == 2) {
                maxormin_index = min_element(temp_descendents_hvalues.begin(), temp_descendents_hvalues.end()) - temp_descendents_hvalues.begin();
            }
            else {
                maxormin_index = max_element(temp_descendents_hvalues.begin(), temp_descendents_hvalues.end()) - temp_descendents_hvalues.begin();
            }

            for (auto i = 0; i < gt.set_of_nodes.size(); i++) {
                if (gt.set_of_nodes[i].id == temp_descendents[maxormin_index])
                    maxormin_node = gt.set_of_nodes[i];
            }

            temp_descendents.clear();
            temp_descendents_hvalues.clear();
            return maxormin_node;
        }
        else {
            return current_node;
        }
    }
}