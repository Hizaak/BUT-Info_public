<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Reservation extends Model
{
    use HasFactory;
    protected $primarykey='codeReservation';
    protected $fillable=['codeReservation','datereservation','datealler',
    'dateretour'];
   // protected $timestamps=false;
    public function client()
    {return $this->belongsTo('App\Client');}
}
