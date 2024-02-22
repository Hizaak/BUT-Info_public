<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Sauce extends Model
{
    use HasFactory;
    protected $fillable = [
        'userID',
        'name',
        'manufacturer',
        'description',
        'mainPepper',
        'imageURL',
        'heat',
        'likes',
        'dislikes',
        'userLiked',
        'userDisliked',
    ];
}