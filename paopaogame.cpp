#include<conio.h>
#include<iostream>
#include<utility>
#include<map>
using namespace std;

class map_point {
private:
    //初始化整张地图
    char m[15][17] = { {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                       {'#','*','#',' ','#','*',' ','*',' ','*',' ','*','#',' ',' ','*','#'},
                       {'#',' ','*','*','*','*','*','#',' ','#',' ','*',' ',' ',' ','#','#'},
                       {'#',' ','#','#',' ','#','*','#','*',' ','*','#',' ','#','*',' ','#'},
                       {'#',' ','*',' ',' ',' ','*','#','*','#','*',' ',' ',' ',' ','#','#'},
                       {'#',' ','#','#',' ','#',' ','*','*',' ','#','#',' ','#','*','*','#'},
                       {'#','*','*','#',' ','#',' ','#','#','*','*','*','*','*','*',' ','#'},
                       {'#',' ','#',' ','#','*','#','#','#','*','#','#',' ','#','#','*','#'},
                       {'#',' ',' ',' ','*','*','*','*','*','*','*','#','*','*','*',' ','#'},
                       {'#',' ','#','#',' ','#','#','*','#','#',' ','#',' ','#','#','*','#'},
                       {'#','*',' ',' ',' ',' ',' ','*',' ','#',' ',' ',' ',' ','*',' ','#'},
                       {'#','*','#','#',' ','#','#','*','*','*','*','#',' ','#','#','*','#'},
                       {'#','*','*','#',' ',' ','*','*','#','#',' ','*',' ','*','#','*','#'},
                       {'#','*',' ',' ','*','*','#',' ','*','*',' ','#',' ','*',' ','*','#'},
                       {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
    };
    map<string, int>point{ {"player1",0},{"player2",0},{"computer1",0},{"computer2",0} };
public:
    char get_obj(int x, int y) {
        return m[x][y];
       
    }
    void change_map(int x,int y,char c) {
        m[x][y] = c;
        return;
    }
    void change_point() {

    }
    int get_point(string str) {
        return point[str];
    }
    void type_map() {
        for (int i = 0; i < 15; i++) {            puts(m[i]);        }        cout << "Player1: " << get_point("player1") << endl;        cout << "Player2: " << get_point("player2") << endl;        cout << "Computer1: " << get_point("computer1") << endl;        cout << "Computer2: " << get_point("computer2") << endl;
    };
    // 在这里随机产生一个道具
    void items(int x, int y) {

    }
};
//定义全局类对象game_map
map_point game_map;
//记录每个人的炸弹的信息,每个人的炸弹打中了几个人。class bomb {private:    pair<int, int>location;    char symbol = 'o';    int power=1; //这个炸弹的威力    bool ifbomb = false;    int kills = 0;    char belong;public:    //放炸弹    void putbomb(int x,int y) {        if (ifbomb) return;        game_map.change_map(x, y, symbol);        location.first = x;        location.second = y;        game_map.type_map();        ifbomb = true;    }    //炸弹爆炸，出现炸弹光波'x'    void finish() {        ifbomb = false;        bool stop = false;        game_map.change_map(location.first, location.second, 'x');        //向上炸        for (int i = 1; i <= power; i++) {            if (stop) break;            switch (game_map.get_obj(location.first, location.second + i)) {            case ' ':game_map.change_map(location.first, location.second + i, 'x'); break;            case '*':game_map.change_map(location.first, location.second + i, 'x'); stop = true;                 game_map.items(location.first, location.second + i); break;            case '#':stop = true; break;            case '1':            case '2':            case '3':            case '4':            }        }    }    void renew_power() {        power++;    }    void get_belong(char x) {        belong = x;    }};class player {private:    pair<int, int> location;    char symbol;  //玩家的符号 分别为'1'  '2'  '3'  '4'    char state = 'l';    bomb b;  //每个玩家拥有自己的炸弹类public:    player(int x, int y, char symbol) {        location.first = x;        location.second = y;        this->symbol = symbol;        b.get_belong(symbol);    }    // wsad ikjl    // 更新人物的位置并在图中显示出来    void update_location(int type,map_point &m) {        int &f = location.first; int &s = location.second;        switch (type) {        case 'w':if (m.get_obj(f, s, 'w') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                 m.change_map(f, s, ' ');             f++;             m.change_map(f, s, symbol); break;        }                else break;        case 'i':if (m.get_obj(f, s, 'w') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                 m.change_map(f, s, ' ');             f++;             m.change_map(f, s, symbol); break;        }                else break;        case 's':if (m.get_obj(f, s, 's') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                 m.change_map(f, s, ' ');             f--;             m.change_map(f, s, symbol); break;        }                else break;        case 'k':if (m.get_obj(f, s, 's') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                 m.change_map(f, s, ' ');             f--;             m.change_map(f, s, symbol); break;        }                else break;        case 'a':if (m.get_obj(f, s, 'a') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                 m.change_map(f, s, ' ');             s--;             m.change_map(f, s, symbol); break;        }                else break;        case 'j':if (m.get_obj(f, s, 'a') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                 m.change_map(f, s, ' ');             s--;             m.change_map(f, s, symbol); break;        }                else break;        case 'd':if (m.get_obj(f, s, 'd') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                 m.change_map(f, s, ' ');             s++;             m.change_map(f, s, symbol); break;        }                else break;        case 'l':if (m.get_obj(f, s, 'd') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                m.change_map(f, s, ' ');            s++;            m.change_map(f, s, symbol); break;        }                else break;        }    }    //获得人的位置    pair<int, int>get_location() {        return(location);    }    //获得人的状态，死，活    char get_state() {        return state;    }};player p1(3,3,'1'); player p2(3,13,'2'); player c1(13,3,'3'); player c2(13,13,'4');int main() {}