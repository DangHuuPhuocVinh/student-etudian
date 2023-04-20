
public class Paiement {
	private double montant;
	private TypePaiment modeDePaiment;
	
	Paiement(){
		this.montant = 0;
	}
	
	Paiement(int montant){
		this.montant = montant;
	}
	
	double getMontant() {
		return this.montant;
	}
	
	double setMontant(int mont) {
		return this.montant = mont;
	}
	
	void operation() {
		
	}
}
