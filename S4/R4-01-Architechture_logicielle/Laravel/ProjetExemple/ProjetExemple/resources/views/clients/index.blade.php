@extends('clients.layout')

@section('content')
    <div class="row">
        <div class="col-lg-12 margin-tb">
            <div class="float-end">
                <a class="btn btn-outline-success" href="{{ route('clients.create') }}"> Créer un nouveau client</a>
            </div>
        </div>
    </div>

    @if ($message = Session::get('success'))
        <div class="alert alert-success">
            <p>{{ $message }}</p>
        </div>
    @endif

    <table class="table table-bordered">
        <tr>
            <th>Numeroclient</th>
            <th>Nom </th>
            <th>Email</th>
            <th>Carte bancaire</th>
            <th width="280px">Action</th>
        </tr>
        @foreach ($clients as $client)
        <tr>

            <td>{{ $client->numeroclient }}</td>
            <td>{{ $client->nom }}</td>
            <td>{{ $client->email }}</td>
            <td>{{ $client->cartebancaire }}</td>
            <td>
                <form action="{{ route('clients.destroy',$client->numeroclient) }}" method="POST">

                    <a class="btn btn-outline-primary" href="{{ route('clients.show',$client->numeroclient) }}">Montrer</a>

                    <a class="btn btn-outline-success" href="{{ route('clients.edit',$client->numeroclient) }}">Éditer</a>

                    @csrf
                    @method('DELETE')

                    <button type="submit" class="btn btn-outline-danger">Supprimer</button>
                </form>
            </td>
        </tr>
        @endforeach
    </table>
    <div class="d-flex justify-content-center pagination-lg">
    {!! $clients->links('pagination::bootstrap-4') !!}
      </div>
@endsection
