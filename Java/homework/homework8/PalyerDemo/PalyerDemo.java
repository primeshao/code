public class PalyerDemo {
	public static void main(String args[]) {
		Gymnastics class1=new Gymnastics();
		School class2=new School();
		System.out.println("School test:");
		System.out.println("Average:"+class1.getAverage());
		System.out.println("Gymnastics test:");
		System.out.println("Average:"+class2.getAverage());
	}

}
interface ComputerAverage{
	double getAverage();
}
class Gymnastics implements ComputerAverage{
	double score[]= {72,98,45,76,12,56,95,66.8,44,77};
	public double getAverage() {
		double sum=0.0;
		double max=score[0];
		double min=score[0];
		for(int i=0;i<score.length;i++) {
			sum+=score[i];
			if(score[i]>max) {
				max=score[i];
			}
			if(score[i]<min) {
				min=score[i];
			}
		}
		return (sum-max-min)/(score.length-2);
	}
}
class School implements ComputerAverage{
	double score[]= {72,98,45,76,12,56,95,66.8,44,77};
	public double getAverage() {
		double sum=0.0;
		for(int i=0;i<score.length;i++) {
			sum+=score[i];	
		}
		return sum/score.length;
	}
}