void main()
{
	Datum* A1=new Datum[3];
	A1[0]._godina = 2017;
	A1[1]._godina = 2017;
	A1[2]._godina = 2017;


	Datum** A2=new Datum*[3];

	A2[0] = new Datum;
	A2[1] = new Datum;
	A2[2] = new Datum;

	A2[0]->_godina = 2017;
	A2[1]->_godina = 2017;
	A2[2]->_godina = 2017;
}
