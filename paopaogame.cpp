#include<conio.h>
#include<iostream>
#include<utility>
#include<map>
using namespace std;

class map_point {
private:
    //��ʼ�����ŵ�ͼ
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
    // �������������һ������
    void items(int x, int y) {

    }
};
//����ȫ�������game_map
map_point game_map;
//��¼ÿ���˵�ը������Ϣ,ÿ���˵�ը�������˼����ˡ�class bomb {private:    pair<int, int>location;    char symbol = 'o';    int power=1; //���ը��������    bool ifbomb = false;    int kills = 0;    char belong;public:    //��ը��    void putbomb(int x,int y) {        if (ifbomb) return;        game_map.change_map(x, y, symbol);        location.first = x;        location.second = y;        game_map.type_map();        ifbomb = true;    }    //ը����ը������ը���Ⲩ'x'    void finish() {        ifbomb = false;        bool stop = false;        game_map.change_map(location.first, location.second, 'x');        //����ը        for (int i = 1; i <= power; i++) {            if (stop) break;            switch (game_map.get_obj(location.first, location.second + i)) {            case ' ':game_map.change_map(location.first, location.second + i, 'x'); break;            case '*':game_map.change_map(location.first, location.second + i, 'x'); stop = true;                 game_map.items(location.first, location.second + i); break;            case '#':stop = true; break;            case '1':            case '2':            case '3':            case '4':            }        }    }    void renew_power() {        power++;    }    void get_belong(char x) {        belong = x;    }};class player {private:    pair<int, int> location;    char symbol;  //��ҵķ��� �ֱ�Ϊ'1'  '2'  '3'  '4'    char state = 'l';    bomb b;  //ÿ�����ӵ���Լ���ը����public:    player(int x, int y, char symbol) {        location.first = x;        location.second = y;        this->symbol = symbol;        b.get_belong(symbol);    }    // wsad ikjl    // ���������λ�ò���ͼ����ʾ����    void update_location(int type,map_point &m) {        int &f = location.first; int &s = location.second;        switch (type) {        case 'w':if (m.get_obj(f, s, 'w') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                 m.change_map(f, s, ' ');             f++;             m.change_map(f, s, symbol); break;        }                else break;        case 'i':if (m.get_obj(f, s, 'w') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                 m.change_map(f, s, ' ');             f++;             m.change_map(f, s, symbol); break;        }                else break;        case 's':if (m.get_obj(f, s, 's') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                 m.change_map(f, s, ' ');             f--;             m.change_map(f, s, symbol); break;        }                else break;        case 'k':if (m.get_obj(f, s, 's') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                 m.change_map(f, s, ' ');             f--;             m.change_map(f, s, symbol); break;        }                else break;        case 'a':if (m.get_obj(f, s, 'a') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                 m.change_map(f, s, ' ');             s--;             m.change_map(f, s, symbol); break;        }                else break;        case 'j':if (m.get_obj(f, s, 'a') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                 m.change_map(f, s, ' ');             s--;             m.change_map(f, s, symbol); break;        }                else break;        case 'd':if (m.get_obj(f, s, 'd') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                 m.change_map(f, s, ' ');             s++;             m.change_map(f, s, symbol); break;        }                else break;        case 'l':if (m.get_obj(f, s, 'd') == ' ') {            if (m.get_obj(f, s, ' ') != 'o')                m.change_map(f, s, ' ');            s++;            m.change_map(f, s, symbol); break;        }                else break;        }    }    //����˵�λ��    pair<int, int>get_location() {        return(location);    }    //����˵�״̬��������    char get_state() {        return state;    }};player p1(3,3,'1'); player p2(3,13,'2'); player c1(13,3,'3'); player c2(13,13,'4');int main() {}