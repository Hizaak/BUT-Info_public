import { Component, Input, OnInit } from '@angular/core';
import { Rapport } from '../models/rapport';

@Component({
  selector: 'app-rapport',
  templateUrl: './rapport.component.html',
  styleUrls: ['./rapport.component.scss']
})
export class RapportComponent implements OnInit {
  @Input () rapport!: Rapport;
  unRapport!: Rapport;
  nomRapport!: string;

  constructor() { }

  ngOnInit(): void { 
  }
}