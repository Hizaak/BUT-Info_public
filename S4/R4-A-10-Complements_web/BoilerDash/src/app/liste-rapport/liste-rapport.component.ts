import { Component, OnInit } from '@angular/core';
import { Observable, tap } from 'rxjs';
import { Rapport } from '../models/rapport';
import { RapportsService } from '../services/rapports.service';
import { Router } from '@angular/router';


@Component({
  selector: 'app-liste-rapport',
  templateUrl: './liste-rapport.component.html',
  styleUrls: ['./liste-rapport.component.scss']
})
export class ListeRapportComponent implements OnInit {
  listeRapports$!: Observable<Rapport[]>;

  constructor(private monServiceRapports: RapportsService, private routeur: Router) { }

  ngOnInit(): void {
    this.listeRapports$ = this.monServiceRapports.getAllRapports(); 
  }


  clickSupprimerRapport(rapport: Rapport) {
    this.monServiceRapports.supprimerRapport(rapport).pipe(
        tap(() => window.location.reload())
      ).subscribe();
  }
}
