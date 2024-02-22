import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { HttpClientModule } from '@angular/common/http';
import { AppComponent } from './app.component';
import { HeaderComponent } from './header/header.component';
import { RapportComponent } from './rapport/rapport.component';
import { ListeRapportComponent } from './liste-rapport/liste-rapport.component';
import { AppRoutingModule } from './app-routing.module';
import { HomeComponent } from './home/home.component';
import { AjouterRapportComponent } from './ajouter-rapport/ajouter-rapport.component';
import { ReactiveFormsModule } from '@angular/forms';

@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    RapportComponent,
    ListeRapportComponent,
    HomeComponent,
    AjouterRapportComponent
    
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpClientModule,
    ReactiveFormsModule],
  providers: [],
  
  bootstrap: [AppComponent]
})
export class AppModule { }
