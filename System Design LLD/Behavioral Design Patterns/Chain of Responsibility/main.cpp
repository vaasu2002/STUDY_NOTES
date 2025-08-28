#include <iostream>
#include <string>
// Chain of responsibility Design Pattern

class Player{
public:
    std::string m_name;
    int m_attack,m_defense;
    Player(const std::string& name,int attack,int defense):m_name(name),m_attack(attack),m_defense(defense){}
};

class PlayerModifier{
    PlayerModifier* next{nullptr};
    protected:
    Player& m_player;
    public:
    PlayerModifier(Player& player):m_player(player){}
    void add(PlayerModifier* playerModifier){
        if(next==nullptr){
            next = playerModifier;
        }
        else{
            next->add(playerModifier);
        }
    }
    virtual void handle(){
        if(next){
            next->handle();
        }
    }
};

class DoubleAttackModifier: public PlayerModifier{
    public:
    DoubleAttackModifier(Player& player):PlayerModifier(player){}
    void handle() override {
        m_player.m_attack *= 2;
        PlayerModifier::handle();
    }
};

class IncreaseAttackModifier: public PlayerModifier{
    public:
    IncreaseAttackModifier(Player& player):PlayerModifier(player){}
    void handle() override {
        m_player.m_attack+=1;
        PlayerModifier::handle();
    }
};

int main(){
    Player p("Vaasu",130,90);
    PlayerModifier root{p};
    DoubleAttackModifier r1{p};
    IncreaseAttackModifier r2{p};
    root.add(&r1);
    root.add(&r2);
    // root.add(&r2);
    // root.add(&r1);
    root.handle();
    std::cout<<p.m_attack<<std::endl;
}






