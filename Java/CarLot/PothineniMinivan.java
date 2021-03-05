public class PothineniMinivan extends PothineniVehicle
{
	public PothineniMinivan(int FC,int FH,int S,double C)
	{
		super(FC,FH,S,C);
	}
	
	public String cargoContainer()
	{
		return "Trunk space is " + Cargo;
	}
	
	public String Description()
	{
		return "This minivan can seat " + Seating + " passangers.\nThe minivan has a cargo volume of " + Cargo + ".\nThe fuel economy is " + FuelCity + "city and " + FuelHigh + "highway miles.";
	} 
}