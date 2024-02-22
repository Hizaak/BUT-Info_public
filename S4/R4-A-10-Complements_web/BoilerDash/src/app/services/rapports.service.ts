import { HttpClient, HttpClientModule } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Rapport } from '../models/rapport';
import { Observable } from 'rxjs';
import { map, switchMap } from 'rxjs/operators';
// import { InterventionInterface } from '../models/intervention-interface';


@Injectable({
  providedIn: 'root'
})
export class RapportsService {

  constructor(private http: HttpClient) { }

  getAllRapports(): Observable<Rapport[]> {
    return this.http.get<Rapport[]>('http://localhost:3000/rapports');
  }

  getRapportById(id: number): Observable<Rapport> {
    const rapport = this.http.get<Rapport>('http://localhost:3000/rapports/' + id);
    if (rapport === undefined) {
      throw new Error('Rapport non trouvé');
    }
    return rapport;
  }

  ajouterRapport(rapports: Rapport): Observable<Rapport> {
    return this.getAllRapports().pipe(
      map(rapports => [...rapports].sort((a,b) => a.id - b.id)),
      map(rapports_tries => rapports_tries[rapports_tries.length - 1]),
      map(rapports_max => {if (rapports_max !== undefined) {(rapports.id = rapports_max.id + 1)}}),
      switchMap(() => this.http.post<Rapport>('http://localhost:3000/rapports', rapports))
    );
  }

  supprimerRapport(rapport: Rapport): Observable<Rapport> {
    const leRapport = this.http.delete<Rapport>('http://localhost:3000/rapports/' + rapport.id);
    if (rapport === undefined) {
      throw new Error('Rapport non trouvé');
    }
    return leRapport;
  }
}
