#include <iostream>
using namespace std;

enum CPU_Rank {P1=1, P2, P3, P4, P5, P6, P7};
class CPU
{
private:
	CPU_Rank rank;
	int frequency;
	float voltage;
public:
	CPU (CPU_Rank r, int f, float v)
	{
		rank = r;
		frequency = f;
		voltage = v;
		cout << "CPU made!" << endl;
	}
	~CPU () { cout << "destructed" << endl; }
	CPU_Rank getRank() const { return rank; }
	int getFrequency() const { return frequency; }
	float getVoltage() const { return voltage;}

	void setRank(CPU_Rank r) { rank = r; }
	void setFrequency(int f) { frequency = f; }
	void setVoltage(float v) { voltage = v; }

	void Run() { cout << "CPU runnin!" << endl; }
	void Stop() { cout << "CPU pooooooped" << endl; }
};
int main() {
	CPU a(P6, 300, 0);
	a.Run();
	a.Stop();
	return 0;
}