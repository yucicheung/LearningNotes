#include<iostream>

//业务
class Operation
{
	private:
		double numberA;
		double numberB;
		string operate;
	public:
		double Operation(double a=0,double b=0,string operate):NumberA(a),NumberB(b),operate(operate){};
		virtual double getResult()=0;
		void setNumberA(double value){NumberA=value;}
		double getNumberA(){return NumberA;}
		double setNumberB(double value){NumberB=value;}
		double getNumberB(){return NumberB;}
}


class OperationAdd:public Operation
{
	public:
		double getResult()return (numberA+numberB);
}


class OperationSub:public Operation
{
	public:
		double getResult()return (numberA-numberB);
}

class OperationDiv:public Operation
{
	public:
		double getResult(){if(!numberB)return (numberA/numberB);}
}

class OperationMul: public Operation
{
	public:
		double getResult(){return (numberA*numberB);}
}

//工厂模式
class OperationFactory
{
	public:
		void OperationFactory(operate);
		createOperate(operate)
		{
			switch(operate)
			{
				case "+":
					return OperationDiv()
			}
		}
	private:
		string operate;
}



//界面
int main()
{
getInput();
oper = OperationFactory.createOperate();
return 0;
}	
