using namespace std;

class TestScores{
private:
    double score1;
    double score2;
    double score3;    
public:
    TestScores(){
        score1 = 0.00;
        score2 = 0.00;
        score3 = 0.00;
    }
    void setTestScore1(double score){
        score1 = score;
    }
    void setTestScore2(double score){
        score2 = score;        
    }
    void setTestScore3(double score){
        score3 = score;        
    }
    double getScore1() const{
        return score1;
    }
    double getScore2() const{
        return score2;
    }
    double getScore3() const{
        return score3;
    }
    double getAverage()const{
        double average = (score1 + score2 + score3) / 3;
        return average;
    }
};
