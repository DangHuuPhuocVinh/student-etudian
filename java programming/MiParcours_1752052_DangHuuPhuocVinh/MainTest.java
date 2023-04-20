public class MainTest {

	public static void main(String[] args) {
		/* Création des articles */
		Article article1 = new Article("HP Pavilion 14-ce1000nf PC Ultraportable", "HP Pavilion 14-ce1000nf PC Ultraportable 14\'\' FHD IPS Argent (Intel Core i5, RAM 8 Go, SSD 256 Go, AZERTY, Windows 10)",1.59 ,699.0);
		Article article2 = new Article("Tablette Fire 7", "Tablette Fire 7, écran 7\", 16 Go (Noir) - avec offres spéciales",	0.28, 70.0);
		Article article3 = new Article("DOQAUS Casque Bluetooth sans Fil","DOQAUS Casque Bluetooth sans Fil, [Jusqu 52 Heures] Pliable Casque Stéréo sans Fil Hi-FI, 3 Modes EQ, Protège-Oreilles Mous de Protéines, Microphone intégré ＆ Mode Filaire, pour PC/Phone/iPad (Noir) [Classe énergétique A+++]",0.25,36.99);
		System.out.println("-------------------------------------------------------------------");
		System.out.println("Création des articles");
		System.out.println("-------------------------------------------------------------------");
		System.out.println(article1);
		System.out.println(article2);
		System.out.println(article3);
		/* Création des commandes détaillées */
		CommandeDetaillee commandeDetaillee1 = new CommandeDetaillee(article1, 2);
		CommandeDetaillee commandeDetaillee2 = new CommandeDetaillee(article2, 1);
		CommandeDetaillee commandeDetaillee3 = new CommandeDetaillee(article2, 4);
		CommandeDetaillee commandeDetaillee4 = new CommandeDetaillee(article3, 1);
		System.out.println("-------------------------------------------------------------------");
		System.out.println("Création des commandes détaillées");
		System.out.println("-------------------------------------------------------------------");
		System.out.println(commandeDetaillee1 + "\n");
		System.out.println(commandeDetaillee2);
		/* Création des commandes*/
		Commande commande1 = new Commande();
		commande1.ajouterUneCommandeDetaillee(commandeDetaillee1);
		commande1.ajouterUnPaiement(new Paiement(2000)); /* Attendre à lever une exception ici */
		
		Commande commande2 = new Commande();
		commande2.ajouterUneCommandeDetaillee(commandeDetaillee2);
		commande2.ajouterUnPaiement(new Paiement(-100)); /* Attendre à lever une exception ici */
		
		Commande commande3 = new Commande();
		commande3.ajouterUneCommandeDetaillee(commandeDetaillee3);
		//commande3.ajouterUneCommandeDetaillee(commandeDetaillee4);
		commande3.ajouterUnPaiement(new Paiement(200));
		System.out.println("-------------------------------------------------------------------");
		System.out.println("Création des commandes");
		System.out.println("-------------------------------------------------------------------");
		System.out.println(commande1);
		
		/* Création des clients*/
		Client client1 = new Client("Sylvie", "Boldo", "17 rue de Paris, Lyon");
		Client client2 = new Client("Nguyen Van", "A", "227 Nguyen Van Cu, quan 5, thanh pho HCM");
		client1.ajouterUneCommande(commande1);
		client1.ajouterUneCommande(commande2);
		commande2.setEtat(TypeEtat.ACCEPTE);
		client2.ajouterUneCommande(commande3);
		commande3.setEtat(TypeEtat.ENVOYE);
		
		System.out.println("-------------------------------------------------------------------");
		System.out.println("Création des clients");
		System.out.println("-------------------------------------------------------------------");
		System.out.println(client1 + "\n");
		System.out.println(client2 + "\n");
	}

}
