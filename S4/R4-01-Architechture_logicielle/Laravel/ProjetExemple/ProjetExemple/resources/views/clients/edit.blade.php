@extends('clients.layout')

@section('content')
    <div class="row">
        <div class="col-lg-12 margin-tb">
            <div class="float-start">
                <h2>Modifier les informations du client</h2>
            </div>
            <div class="float-end">
                <a class="btn btn-outline-primary" href="{{ route('clients.index') }}"> Retour</a>
            </div>
        </div>
    </div>

    @if ($errors->any())
        <div class="alert alert-danger">
            <strong>Oups! </strong> Il y a eu des problèmes avec votre entrée.<br><br>
            <ul>
                @foreach ($errors->all() as $error)
                    <li>{{ $error }}</li>
                @endforeach
            </ul>
        </div>
    @endif

     <form action="{{ route('clients.update',$client->numeroclient) }}" method="POST">
        @csrf
        @method('PUT')
        <div class="row">
        <div class="col-xs-6 col-sm-6 col-md-6">
            <div class="form-group">
                <strong>Numéro client:</strong>
                <input type="text" name="numeroclient" value="{{ $client->numeroclient }}"class="form-control" placeholder="Saisir un numéro">
            </div>
        </div>
        <div class="col-xs-6 col-sm-6 col-md-6">
            <div class="form-group">
                <strong>Nom :</strong>
                <input type="text" name="nom" value="{{ $client->nom }}" class="form-control" placeholder="Saisir le nom ">
            </div>
        </div>
        </div>
        <div class="row">
            <div class="col-xs-6 col-sm-6 col-md-6">
                <div class="form-group">
                    <strong>Adresse email:</strong>
                    <input type="text" name="email" value="{{ $client->email }}" class="form-control" placeholder="Saisir un email">
                </div>
            </div>
            <div class="col-xs-6 col-sm-6 col-md-6">
                <div class="form-group">
                    <strong>Carte Bancaire:</strong>
                    <input type="text" name="cartebancaire" value="{{ $client->cartebancaire }}" class="form-control" placeholder="Saisir une carte">
                </div>
            </div>
        </div>

            <div class="col-xs-12 col-sm-12 col-md-12 text-center pt-4">
              <button type="submit" class="btn btn-primary">Soumettre</button>
            </div>
        </div>

    </form>
@endsection
