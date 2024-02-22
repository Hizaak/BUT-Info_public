import { Component, OnInit } from '@angular/core';
import { FormGroup, FormBuilder, Validators } from '@angular/forms';
import { map, Observable, tap } from 'rxjs';
import { Rapport } from '../models/rapport';
import { RapportsService } from '../services/rapports.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-ajouter-rapport',
  templateUrl: './ajouter-rapport.component.html',
  styleUrls: ['./ajouter-rapport.component.scss']
})
export class AjouterRapportComponent implements OnInit{
  formulaire!: FormGroup;
  rapportActuel$!: Observable<Rapport>;

  constructor(private formBuilder: FormBuilder, private monService: RapportsService, private routeur: Router) { }


  ngOnInit(): void {
    this.formulaire = this.formBuilder.group({
      nomTechnicien: [null, [Validators.required, Validators.minLength(3)]],
      nomClient: [null, [Validators.required, Validators.minLength(3)]],
      adresseClient: [null, [Validators.required, Validators.minLength(3)]],
      marque: [null, [Validators.required, Validators.minLength(3)]],
      modele: [null, [Validators.required, Validators.minLength(3)]],
      dateMiseEnService: [null, [Validators.required]],
      dateIntervention: [null, [Validators.required]],
      numeroSerie: [null, [Validators.required, Validators.minLength(3)]],
      description: [null, [Validators.required, Validators.minLength(3)]],
      duree: [null, [Validators.required, Validators.min(0)]],
    },
    {
      updateOn: 'blur'
    });

    this.rapportActuel$ = this.formulaire.valueChanges.pipe(map(formValue => (
      {
        id: 0,
        nomTechnicien: formValue.nomTechnicien,
        nomClient: formValue.nomClient,
        adresseClient: formValue.adresseClient,
        marque: formValue.marque,
        modele: formValue.modele,
        dateMiseEnService: formValue.dateMiseEnService,
        dateIntervention: formValue.dateIntervention,
        numeroSerie: formValue.numeroSerie,
        description: formValue.description,
        duree: formValue.duree,
      }
    )))
  }

 validerRapport() {
    let nouveauRapport: Rapport = {
      id: 0,
      nomTechnicien: this.formulaire.get('nomTechnicien')?.value,
      nomClient: this.formulaire.get('nomClient')?.value,
      adresseClient: this.formulaire.get('adresseClient')?.value,
      marque: this.formulaire.get('marque')?.value,
      modele: this.formulaire.get('modele')?.value,
      dateMiseEnService: this.formulaire.get('dateMiseEnService')?.value,
      dateIntervention: this.formulaire.get('dateIntervention')?.value,
      numeroSerie: this.formulaire.get('numeroSerie')?.value,
      description: this.formulaire.get('description')?.value,
      duree: this.formulaire.get('duree')?.value,
  } 
      
  this.monService.ajouterRapport(nouveauRapport).pipe(
      tap(() => this.routeur.navigateByUrl('/liste-rapport'))  
    ).subscribe();  
  }


}
