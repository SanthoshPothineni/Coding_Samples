public abstract class PothineniVehicle
{
	int FuelCity;
	int FuelHigh;
	int Seating;
	double Cargo;
	
	public PothineniVehicle(int FC,int FH,int S,double C)
	{
		FuelCity=FC;
		FuelHigh=FH;
		Seating=S;
		Cargo=C;
	}
	
	public int getFuelCity()
	{
		return FuelCity;
	}
	
	public int getFuelHigh()
	{
		return FuelHigh;
	}
	
	public int getSeating()
	{
		return Seating;
	}
	public double getCargo()
	{
		return Cargo;
	}
	
	abstract public String cargoContainer();
	abstract public String Description();
}