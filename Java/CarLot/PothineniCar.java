public class PothineniCar extends PothineniVehicle
{
	public PothineniCar(int FC,int FH,int S,double C)
	{
		super(FC,FH,S,C);
	}
	
	public String cargoContainer()
	{
		return "Trunk space is " + Cargo;
	}
	
	public String Description()
	{
		return "This car can seat " + Seating + " passangers.\nThe car has a cargo volume of " + Cargo + ".\nThe fuel economy is " + FuelCity + "city and " + FuelHigh + "highway miles.";
	} 
}