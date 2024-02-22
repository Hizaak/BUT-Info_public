@extends('layouts.app')

@section('content')
<div class="container">
    <div class="row justify-content-center">
        <div class="col-md-8">
            <div class="card">
                <div class="card-header">{{ __('Dashboard') }}</div>

                <div class="card-body">
                    @if (session('status'))
                        <div class="alert alert-success" role="alert">
                            {{ session('status') }}
                        </div>
                    @endif

                    
                    <a href="{{ route('afficher1') }}">Afficher 1</a> 
                    <br>
                    <a href="#">Afficher 2</a> <br>
                    <a href="{{ route('session.add') }}">Ajouter des données de session</a><br>
                    <a href="{{ route('session.show') }}">Afficher les données de session</a><br>
                    <a href="{{ route('session.delete') }}">Supprimer les données de session</a><br>
                </div>
            </div>
        </div>
    </div>
</div>
@endsection
