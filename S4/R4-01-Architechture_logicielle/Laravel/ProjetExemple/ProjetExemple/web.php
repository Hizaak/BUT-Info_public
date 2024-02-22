<?php

use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider and all of them will
| be assigned to the "web" middleware group. Make something great!
|
*/

Route::get('/', function () {
    return view('welcome');
});


Auth::routes();

Route::get('/home', [App\Http\Controllers\HomeController::class, 'index'])->name('home');
Route::get('/afficher1/', function () { return 'hello';})->name('afficher1');
Route::get('/add', 'App\Http\Controllers\SessionController@addData')->name('session.add');
Route::get('/show', 'App\Http\Controllers\SessionController@showData')->name('session.show');
Route::get('/delete', 'App\Http\Controllers\SessionController@deleteData')->name('session.delete');


use App\Http\Controllers\ClientController;
Route::resource('clients', ClientController::class);
