export class Rapport{
    id!: number;
    nomTechnicien!: string;
    nomClient!: string;
    adresseClient!: string;
    marque!: string;
    modele!: string;
    dateMiseEnService!: Date;
    dateIntervention!: Date;
    numeroSerie!: string;
    description!: string;
    duree!: number;

    constructor(id: number, nomTechnicien: string, nomClient: string, adresseClient: string, marque: string, modele: string, dateMiseEnService: Date, dateIntervention: Date, numeroSerie: string, description: string, duree: number){
        this.id = id;
        this.nomTechnicien = nomTechnicien;
        this.nomClient = nomClient;
        this.adresseClient = adresseClient;
        this.marque = marque;
        this.modele = modele;
        this.dateMiseEnService = dateMiseEnService;
        this.dateIntervention = dateIntervention;
        this.numeroSerie = numeroSerie;
        this.description = description;
        this.duree = duree;
    }
}