import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { RouterModule,Route } from '@angular/router';
import { HomeComponent } from './home/home.component';
import { ListeRapportComponent } from './liste-rapport/liste-rapport.component';
import { AjouterRapportComponent } from './ajouter-rapport/ajouter-rapport.component';

const routes: Route[] = [
  { path: '', component: HomeComponent },
  { path: 'liste-rapport', component: ListeRapportComponent},
  { path: 'ajouter-rapport', component: AjouterRapportComponent},
  { path: 'Accueil', component: HomeComponent}

];

@NgModule({
  declarations: [],
  imports: [
    CommonModule,
    RouterModule.forRoot(routes)
  ],
  exports: [RouterModule]
})
export class AppRoutingModule { }
