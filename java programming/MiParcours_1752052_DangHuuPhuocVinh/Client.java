
public class Client {
	private String nom;
	private String prenom;
	private String adresse;
	
	Client(){
		this.nom = "";
		this.prenom = "";
		this.adresse = "";
	}
	
	Client(String nom, String prenom, String adresse){
		this.nom = nom;
		this.prenom = prenom;
		this.adresse = adresse;
	}
	
	String getNom(){
		return this.nom;
	}
	
	String getPrenom() {
		return this.prenom;
	}
	
	String getAdresse() {
		return this.adresse;
	}
	
	String setNom(String nom) {
		return this.nom =  nom;
	}
	
	String setPrenom(String prenom) {
		return this.prenom = prenom;
	}
	
	String setAdresse(String adresse) {
		return this.adresse = adresse;
	}
	
	public String toString() {
	    return getClass().getName()+"@"+Integer.toHexString(hashCode());
	}
	
	
}
